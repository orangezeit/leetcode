class Solution {
public:
int dfs(vector<vector<int>>& al, vector<bool>& visited, int i, int& diameter) {
  visited[i] = true;
  auto max_depth = 0;
  for (auto j : al[i]) {
    if (!visited[j]) {
      auto depth = dfs(al, visited, j, diameter);
      diameter = max(diameter, depth + max_depth);
      max_depth = max(depth, max_depth);
    }
  }
  return i == 0 ? diameter : max_depth + 1;
}
int treeDiameter(vector<vector<int>>& edges) {
  int diameter = 0;
  vector<bool> visited(edges.size() + 1);
  vector<vector<int>> al(edges.size() + 1);
  for (auto& e : edges) {
    al[e[0]].push_back(e[1]);
    al[e[1]].push_back(e[0]);
  }
  return dfs(al, visited, 0, diameter);
}
};
