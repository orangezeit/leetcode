struct cell {
    uint8_t value;           // cell value 1..9, 0 if unset
    uint8_t numPossible;     // number of possible (unconstrained) values
    bitset<10> constraints;  // if bitset[v] is 1 then value can't be v
    cell() : value(0), numPossible(9), constraints() {}
};

struct sudoku {
    array<array<cell, 9>, 9> cells;

    bool setValue(int i, int j, int v) {
        cell& c = cells[i][j];
        if (c.value == v) return true;
        if (c.constraints[v]) return false;

        c.value = v;
        c.numPossible = 1;
        c.constraints = 0b1111111110;
        c.constraints.reset(v);

		for (int k = 0; k < 9; k++) {
			if (i != k && !updateConstraint(k, j, v)) return false;
			if (j != k && !updateConstraint(i, k, v)) return false;
			int ix(i / 3 * 3 + k / 3), jx(j / 3 * 3 + k % 3);
			if (ix != i && jx != j && !updateConstraint(ix, jx, v)) return false;
		}

		return true;
    }

    bool updateConstraint(int i, int j, int excluded){
		cell& c = cells[i][j];
		if (c.constraints[excluded]) return true;
		if (c.value == excluded) return false;
		c.constraints.set(excluded);
		if (--c.numPossible > 1)
			return true;
		for (int v = 1; v <= 9; v++)
			if (!c.constraints[v])
				return setValue(i, j, v);
		assert(false);
	}

	bool fillEmpty() {
		vector<int> bt;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (!cells[i][j].value)
					bt.emplace_back(i * 9 + j);

		sort(bt.begin(), bt.end(), [&](const int&a, const int&b) {
			return cells[a / 9][a % 9].numPossible < cells[b / 9][b % 9].numPossible; });

        function<bool(int)> backtrack = [&](int k) {
            if (k == bt.size()) return true;
            int i(bt[k] / 9), j(bt[k] % 9);
            if (cells[i][j].value) return backtrack(k + 1);
            array<array<cell,9>,9> snapshot(cells);
            for (int v = 1; v <= 9; v++)
                if (!cells[i][j].constraints[v]) {
                    if (setValue(i, j, v) && backtrack(k + 1))
                        return true;
                    cells = snapshot;
                }
            return false;
        };

		return backtrack(0);
	}
};

class Solution {
public:
	void solveSudoku(vector<vector<char>> &board) {
	    sudoku s;

		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (board[i][j] != '.' && !s.setValue(i, j, board[i][j] - '0'))
					return;

		if (!s.fillEmpty()) return;

		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				board[i][j] = s.cells[i][j].value + '0';
	}
};
