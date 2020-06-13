class TopVotedCandidate {
private:
    unordered_map<int, int> counter;
    map<int, int> m;
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        int leader(0);
        for (int i = 0; i < persons.size(); ++i) {
            if (++counter[persons[i]] >= counter[leader])
                leader = persons[i];
            m[times[i]] = leader;
        }
    }

    int q(int t) {
        return (--m.upper_bound(t))->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
