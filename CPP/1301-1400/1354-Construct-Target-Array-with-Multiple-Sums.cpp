class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long> pq;
        long s(0);
		// push each element into max-heap, also sum all elements
        for (const int& i: target) {
            pq.push(i);
            s += i;
        }
        if (pq.top() == s) return false;
        while (pq.top() != 1) { // until every element in heap is 1
			// we pop the largest from heap
            long t = pq.top();
            pq.pop();

			// (special case) by induction, [n, 1] -> [n-1, 1] -> ... -> [2, 1] -> [1, 1] is always possible
			if (s - t == 1) return true;
			// if it cannot be formed by other numbers in heap, return false
            if ((2 * t - s) % (s - t) <= 0) return false;

			// otherwise, we push the previous number (possibly from many steps before / accelerate by module)
            pq.push((2 * t - s) % (s - t));
			// update current sum
            s += (2 * t - s) % (s - t) - t;
        }

        return true;
    }
};
