    vector<string> fizzBuzz(int n) {
        vector<string> fb(n);
        
        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0) {
                fb[i-1] = "FizzBuzz";
            } else if (i % 3 == 0) {
                fb[i-1] = "Fizz";
            } else if (i % 5 == 0) {
                fb[i-1] = "Buzz";
            } else {
                fb[i-1] = to_string(i);
            }
        }
        
        return fb;
    }
