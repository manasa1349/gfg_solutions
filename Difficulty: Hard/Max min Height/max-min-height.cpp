class Solution {
public:
    // Helper function to check if target height 'mid' is achievable
    bool check(long long mid, int k, int w, vector<int>& a) {
        int n = a.size();
        // diff array to track range watering updates [i, i + w - 1]
        vector<long long> d(n + 1, 0); 
        long long days = 0, current = 0;

        for (int i = 0; i < n; i++) {
            current += d[i]; // Apply pending range updates at current index
            if (a[i] + current < mid) {
                long long needed = mid - (a[i] + current);
                days += needed;
                current += needed; // Add watering effect to current and future
                
                // Set the endpoint for this watering session
                if (i + w < n) d[i + w] -= needed;
            }
            if (days > k) return false;
        }
        return days <= k;
    }
    int maxMinHeight(vector<int> &arr, int k, int w) {
        int n = arr.size();
        long long low = *min_element(arr.begin(), arr.end());
        long long high = low + k;
        long long ans = low;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid, k, w, arr)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return (int)ans;
    }
};
