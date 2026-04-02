class Solution {
  public:
    int countWays(int n, int k) {
        // code here
        if (n == 1) return k;
        if (n == 2) return k * k;

        long a = k;           // f(n-2)
        long b = (long)k * k; // f(n-1)

        for (int i = 3; i <= n; i++) {
            long curr = (k - 1) * (a + b);
            a = b;
            b = curr;
        }

        return (int)b;

    }
};