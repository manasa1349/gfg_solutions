class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>pre(n+1,vector<int>(m+1,0));
        vector<int>ans;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pre[i][j]=mat[i-1][j-1]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
            }
        }
        for(int i=0;i<queries.size();i++){
            int r1=queries[i][0]+1,c1=queries[i][1]+1,r2=queries[i][2]+1,c2=queries[i][3]+1;
            int val=pre[r2][c2]-pre[r1-1][c2]-pre[r2][c1-1]+pre[r1-1][c1-1];
            ans.push_back(val);
        }
        return ans;
    }
};
