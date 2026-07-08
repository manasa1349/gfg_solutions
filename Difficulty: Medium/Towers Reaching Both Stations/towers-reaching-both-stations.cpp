class Solution {
  public:
    int countCoordinates(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis1(n,vector<int>(m,0));
        vector<vector<int>>vis2(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for (int j = 0; j < m; j++) { q.push({0, j}); vis1[0][j] = true; }
        for (int i = 0; i < n; i++) { q.push({i, 0}); vis1[i][0] = true; }
        int delr[]={0,0,-1,1};
        int delc[]={-1,1,0,0};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+delr[i];
                int nc=c+delc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis1[nr][nc] && mat[nr][nc]>=mat[r][c]){
                    q.push({nr,nc});
                    vis1[nr][nc]=1;
                }
            }
        }
        
        
        for (int j = 0; j < m; j++) { q.push({n - 1, j}); vis2[n - 1][j] = true; }
        for (int i = 0; i < n; i++) { q.push({i, m - 1}); vis2[i][m - 1] = true; }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+delr[i];
                int nc=c+delc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis2[nr][nc] && mat[nr][nc]>=mat[r][c]){
                    q.push({nr,nc});
                    vis2[nr][nc]=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=(vis1[i][j] & vis2[i][j]);
            }
        }
        return ans;
    }
};