class Solution {
  public:
    int func(int k,vector<vector<int>>pre,int n,int m,int x){
        int ans=0;
        for(int i=0;i+k<=n;i++){
            for(int j=0;j+k<=m;j++){
                int val=pre[i+k][j+k]-pre[i+k][j]-pre[i][j+k]+pre[i][j];
                if(val==x){
                    ans++;
                }
            }
        }
        return ans;
    }
    int countSquare(vector<vector<int>>& mat, int x) {
        // code here
        //2D prefix
        // [i-1][j]+[i][j-1]-[i-1][j-1]+[i][j]
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>pre(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+mat[i-1][j-1];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=(func(i,pre,n,m,x));
        }
        return ans;
    }
};