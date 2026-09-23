class Solution {
public:
    int formPyramid(vector<int>& arr) {
        int n = arr.size();

        vector<long long> left(n), right(n);

        // Maximum increasing pyramid height from the left
        left[0] = 1;

        for (int i = 1; i < n; i++) {
            left[i] = min(
                (long long)arr[i],
                left[i - 1] + 1
            );
        }

        // Maximum decreasing pyramid height from the right
        right[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--) {
            right[i] = min(
                (long long)arr[i],
                right[i + 1] + 1
            );
        }

        long long total = 0;
        long long best = 0;

        for (int x : arr) {
            total += x;
        }

        // Try every position as the peak
        for (int i = 0; i < n; i++) {
            long long h = min(left[i], right[i]);

            best = max(best, h * h);
        }

        return total - best;
    }
};