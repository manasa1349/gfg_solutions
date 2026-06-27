class Solution {
  public:
    const int MOD=1e9+7;
    int func(int n,int m,vector<int>&dp){
        if(n<m) return 1;
        if(n==m) return 2;
        if(dp[n]!=-1) return dp[n];
        long long hor=func(n-1,m,dp);
        long long ver=func(n-m,m,dp);
        return dp[n]=(hor+ver)%MOD;
    }
    int countWays(int n, int m) {
        // code here.
        vector<int>dp(n+1,-1);
        return func(n,m,dp);
    }
};