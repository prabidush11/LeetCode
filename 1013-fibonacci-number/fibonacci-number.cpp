class Solution {
public:
    int fibonacci(vector<int>& fibo, int n) {
        if (fibo.size() > n)
            return fibo[n];

        fibo.push_back(fibonacci(fibo, n - 1) +
                       fibonacci(fibo, n - 2));

        return fibo[n];
    }

    int fib(int n) {
        vector<int> fibo = {0, 1};
        return fibonacci(fibo, n);
    }
};