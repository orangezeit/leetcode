class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // move backwards
        deque<int> dq;
        sort(deck.rbegin(), deck.rend());
        for (int i = 0; i < deck.size(); ++i) {
            if (!dq.empty()) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            dq.push_front(deck[i]);
        }
        return vector<int>(dq.begin(), dq.end());
    }
};
