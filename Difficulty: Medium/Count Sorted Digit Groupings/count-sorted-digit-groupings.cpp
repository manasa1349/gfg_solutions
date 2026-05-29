class Solution {
  public:
    long long dp[105][905];

    long long solve(int idx,int prevSum,string &s){
        int n=s.size();

        if(idx==n){
            return 1;
        }

        if(dp[idx][prevSum]!=-1){
            return dp[idx][prevSum];
        }

        long long ans=0;
        int currSum=0;

        for(int j=idx;j<n;j++){
            currSum+=s[j]-'0';

            if(currSum>=prevSum){
                ans+=solve(j+1,currSum,s);
            }
        }

        return dp[idx][prevSum]=ans;
    }
    
    int validGroups(string &s) {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s);
    }
};