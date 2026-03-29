class Solution {
  public:
    int countSubsets(int i, int currSum, int target, vector<int> &arr, vector<vector<int>> &dp){
        int n = arr.size();
    
        // Base case
        if (i == n)
            return (currSum == target) ? 1 : 0;
    
        if (dp[i][currSum] != -1)
            return dp[i][currSum];
    
        // dont include into the subset
        int exclude = countSubsets(i + 1, currSum, target, arr, dp);
    
        int include = 0;
    
        // include only if the element is smaller than the target
        if (currSum + arr[i] <= target)
            include = countSubsets(i + 1, currSum + arr[i], target, arr, dp);
    
        return dp[i][currSum] = include + exclude;
    }

    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int sum = accumulate(arr.begin(), arr.end(), 0);
    
        // check if it is possible to make subsets of given diff
        if ((sum + diff) % 2 != 0 || sum < diff)
            return 0;
    
        int target = (sum + diff) / 2;
    
        // 2D dp array for memoisation
        vector<vector<int>> dp(arr.size() + 1, vector<int>(target + 1, -1));
        return countSubsets(0, 0, target, arr, dp);
    }
};