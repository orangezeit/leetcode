class TweetCounts {
public:
    unordered_map<string, set<int>> tweets;
    TweetCounts() {

    }

    void recordTweet(string tweetName, int time) { // in seconds
        tweets[tweetName].insert(time);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> ans;
        int n(freq[0] == 'm' ? 60 : freq[0] == 'h' ? 3600 : 86400);
        for (int i = startTime; i <= endTime; i += n)
            ans.push_back(distance(tweets[tweetName].lower_bound(i), tweets[tweetName].upper_bound(min(i + n - 1, endTime))));
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
