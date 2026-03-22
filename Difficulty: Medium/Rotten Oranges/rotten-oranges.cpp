class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int,int>> q;
        int fresh = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 2){
                    q.push({i, j});
                }
                else if(mat[i][j] == 1){
                    fresh++;
                }
            }
        }
        
        // Directions: up, down, left, right
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        
        int time = 0;
        
        while(!q.empty() && fresh > 0){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                auto [x, y] = q.front();
                q.pop();
                
                for(auto d : dir){
                    int nx = x + d.first;
                    int ny = y + d.second;
                    
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] == 1){
                        mat[nx][ny] = 2; // rot it
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
            
            time++;
        }
        
        if(fresh == 0) return time;
        return -1;

    }
};