class Twitter {
    unordered_map<int, int> indices; // user id to follower vector index;
    vector<pair<int, int>> tweets; // store recent ten tweets;
    vector<unordered_set<int>> followers; // store followers
public:
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
        if (indices.find(userId) == indices.end()) {
            indices[userId] = followers.size();
            followers.push_back({userId});
        }
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        if (indices.find(userId) == indices.end()) {
            return res;
        }

        for (int i = tweets.size()-1; i >= 0; --i) {
            if (followers[indices[userId]].find(tweets[i].first) != followers[indices[userId]].end()) {
                res.push_back(tweets[i].second);
                if (res.size() == 10) {
                    break;
                }
            }
        }

        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) { // user 1, user 2
        if (indices.find(followerId) == indices.end()) {
            indices[followerId] = followers.size();
            followers.push_back({followerId, followeeId});
        } else {
            followers[indices[followerId]].insert(followeeId);
        }
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId || indices.find(followerId) == indices.end()) {
            return;
        }

        followers[indices[followerId]].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
