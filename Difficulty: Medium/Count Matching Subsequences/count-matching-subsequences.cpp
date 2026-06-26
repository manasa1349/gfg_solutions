class Solution {
  public:
    int const MOD=1e9+7;
    int func(string &s1, string &s2,int i,int j,vector<vector<int>>&dp){
        if(j==s2.size()) return 1;
        if(i==s1.size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        long long ways=func(s1,s2,i+1,j,dp);
        if(s1[i]==s2[j]){
            ways=(ways+func(s1,s2,i+1,j+1,dp))%MOD;
        }
        return dp[i][j]=ways;
    }
    int countWays(string &s1, string &s2) {
        // code here
        vector<vector<int>>dp(s1.size(),vector<int>(s2.size(),-1));
        return func(s1,s2,0,0,dp);
    }
};
