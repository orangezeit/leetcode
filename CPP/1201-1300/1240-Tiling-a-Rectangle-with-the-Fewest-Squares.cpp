class Solution {
public:
	int tilingRectangle(int n, int m) {
		if (n == m) return 1;
		if (n > m) swap(n, m);
		int heights[n] = {};
		int res(m * n);
		dfs(n, m, heights, 0, res);
		return res;
	}

	void dfs(const int& n, const int& m, int heights[], int cnt, int& res) {
		if (cnt >= res) return;

		int left(0), min_height(m);
		for (int i = 0; i < n; i++)
			if (heights[i] < min_height)
				min_height = heights[left = i];

		if (min_height == m) {
			res = min(cnt, res);
			return;
		}

		int right(left);
		while (right < n && heights[left] == heights[right] && right - left + min_height < m) right++;

        // plot the biggest possible square to the rectangle
        for (int i = left; i < right; i++)
            heights[i] += right - left;

        for (int size = right - left; size >= 1; size--) {
            dfs(n, m, heights, cnt + 1, res);

            // update the rectangle to contain the next smaller square
            for (int i = left; i < left + size - 1; i++)
                heights[i]--;
            heights[left + size - 1] -= size;
        }

	}
};
