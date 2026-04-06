class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<long long, int> mp;
        long long sum = 0;
        int maxLen = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            // Case 1: Subarray starting from index 0
            if (sum == k) {
                maxLen = i + 1;
            }

            // Case 2: Check if (sum - k) exists in map
            if (mp.find(sum - k) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum - k]);
            }

            // Only store the first occurrence of a sum to keep the subarray longest
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};
