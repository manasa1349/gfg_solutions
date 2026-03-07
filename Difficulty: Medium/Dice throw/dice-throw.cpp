class Solution {
  public:
    // long long cnt=0;
    // void func(int n,int x,int m){
    //     if(x==0 && n==0){
    //         cnt++;
    //         return;
    //     }
    //     if(n==0)return;
    //     if(x<0) return;
    //     for(int i=1;i<=m;i++){
    //         func(n-1,x-i,m);
    //     }
    // }
    int noOfWays(int m, int n, int x) {
        // code here
        // cnt=0;
        // func(n,x,m);
        // return cnt;
        vector<vector<int>>dp(n+1,vector<int>(x+1,0));
        dp[0][0]=1;
        for(int i=1;i<=x;i++){
            for(int d=1;d<=n;d++){
                for(int f=1;f<=m;f++){
                    if(i>=f){
                        dp[d][i]+=dp[d-1][i-f];
                    }
                }
            }
        }
        return dp[n][x];
    }
};