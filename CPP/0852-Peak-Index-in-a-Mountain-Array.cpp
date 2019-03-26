    int peakIndexInMountainArray(vector<int>& A) {
        // Method 1: Linear Search
        // Time Complexity: O(n)
        
        for (int i = 1; i < A.size()-1; ++i) {
            if (A[i-1] < A[i] && A[i] > A[i+1]) {
                return i;
            }
        }
        
        // Method 2: Binary Search
        // Time Complexity: O(lgn)
        
        int i(1), j(A.size()-2);
        
        while (i <= j) {
            int mid = (i+j) / 2;
            if (A[mid-1] < A[mid] && A[mid] > A[mid+1]) {
                return mid;
            } else if (A[mid-1] < A[mid] && A[mid] < A[mid+1]) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
    }
