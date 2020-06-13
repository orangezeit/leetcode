/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    const string_view host(const string& s) {
        auto it = s.find('/', 7);
        return string_view(s).substr(7, it == string::npos ? string::npos : it - 7);
    }
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        vector<thread> threads;
        vector<string> res({startUrl});
        unordered_set<string> s({startUrl});
        queue<string> q;

        int crawlers(0); // number of crawlers in threads
        mutex mr, mq;    // locks
        condition_variable cv;

        q.push(startUrl);
        string_view h = host(startUrl);

        auto tfn = [&] {
            while (true) {
                string url;

                // deque
                {
                    auto ul = unique_lock(mq);
                    // wait until queue is empty and no active crawlers in threads
                    cv.wait(ul, [&]{ return !q.empty() || !crawlers; });
                    if (q.empty()) break;
                    url = q.front();
                    q.pop();
                    ++crawlers;
                }

                // parse
                vector<string> urls = htmlParser.getUrls(url);
                urls.erase(remove_if(urls.begin(), urls.end(),
                                    [&](const string& s) {return host(s) != h;}),
                          urls.end());
                int m = 0;
                auto lg = lock_guard(mr);

                for (const string& link: urls) {
                    if (s.insert(link).second) {
                        res.push_back(link);
                        ++m;
                    }
                }

                // enque
                {
                    auto ul = unique_lock(mq);
                    --crawlers;
                    for (int i = 0; i < m; ++i)
                        q.push(*(res.rbegin() + i));
                    ul.unlock();
                    cv.notify_all();
                }
            }
        };

        for (auto i = 0; i < 1; ++i)
            threads.emplace_back(tfn);
        tfn();
        for (auto& t: threads) t.join();

        return res;
    }
};
