class Solution {
public:


    bool traverse(vector<int>& colors, const vector<vector<int>>& graph, int index, int color) {
        colors[index] = color;
        for (int i = 0; i < graph[index].size(); ++i) {
            if (colors[graph[index][i]] == color)
                return false;
            if (colors[graph[index][i]] == 0 && !traverse(colors, graph, graph[index][i], -color))
                return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size());

        for (int i = 0; i < graph.size(); ++i)
            if (colors[i] == 0 && !traverse(colors, graph, i, 1))
                return false;
        return true;
    }
};
