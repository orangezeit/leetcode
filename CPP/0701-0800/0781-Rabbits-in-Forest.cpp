class Solution {
public:
    int numRabbits(vector<int>& answers) {

        int base = answers.size();

        sort(answers.begin(), answers.end());
        answers.emplace_back(1000);
        vector<int> counts;
        int c = 0;

        for (int i = 1; i < answers.size(); ++i)
            if(answers[i - 1] != answers[i]) {
                counts.emplace_back(i-c);
                c = i;
            }

        counts.push_back(answers.size()-c-1);

        answers.resize(distance(answers.begin(), unique(answers.begin(), answers.end())));

        for (int i = (answers[0] == 0); i < answers.size(); ++i)
            if (counts[i] % (answers[i]+1))
                base += answers[i]+1-counts[i] % (answers[i]+1);

        return base;
    }
};
