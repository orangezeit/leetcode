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

    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        queue<string> q; // bfs
        unordered_set<string> visited = {startUrl};
        auto it = startUrl.find('/', 7) == string::npos ? startUrl.end() : startUrl.begin() + startUrl.find('/', 7);
        string hostname(startUrl.begin() + startUrl.find('.') + 1, it);
        q.push(startUrl);

        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                string url = q.front();
                q.pop();


                //cout << hostname << endl;
                vector<string> suburls = htmlParser.getUrls(url);
                for (const string& suburl: suburls)
                    if (!visited.count(suburl)) {
                        if (suburl.find(hostname) != string::npos) {
                            visited.insert(suburl);
                            q.push(suburl);
                        }

                    }
            }
        }

        return vector<string>(visited.begin(), visited.end());
    }
};
