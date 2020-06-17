class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        unordered_map<int, int> videos;
        for (int i = 0; i < clips.size(); ++i) {
            videos[clips[i][0]] = max(videos[clips[i][0]], clips[i][1]);
        }

        if (videos.find(0) == videos.end()) return -1;

        int p1 = 0;
        int p2 = videos[0];
        int t = 1;

        while (p2 < T) {
            int temp = 0;
            for (int i = p1 + 1; i <= p2; ++i) {
                temp = max(temp, videos[i]);
            }
            if (temp <= p2) return -1;
            p1 = videos[0];
            p2 = temp;
            t++;
        }

        return t;
    }
};
