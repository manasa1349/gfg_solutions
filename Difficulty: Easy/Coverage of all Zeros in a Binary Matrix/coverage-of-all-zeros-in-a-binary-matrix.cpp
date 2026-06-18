class Solution {
public:
    int findCoverage(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> left(n, vector<int>(m, 0));
        vector<vector<int>> right(n, vector<int>(m, 0));
        vector<vector<int>> up(n, vector<int>(m, 0));
        vector<vector<int>> down(n, vector<int>(m, 0));
        
        // Fill Left and Up
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (j > 0) left[i][j] = left[i][j-1];
                if (mat[i][j] == 1) left[i][j] = 1;
                
                if (i > 0) up[i][j] = up[i-1][j];
                if (mat[i][j] == 1) up[i][j] = 1;
            }
        }
        
        // Fill Right and Down
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if (j < m - 1) right[i][j] = right[i][j+1];
                if (mat[i][j] == 1) right[i][j] = 1;
                
                if (i < n - 1) down[i][j] = down[i+1][j];
                if (mat[i][j] == 1) down[i][j] = 1;
            }
        }
        
        int total = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    if(j > 0 && left[i][j-1]) total++;
                    if(j < m - 1 && right[i][j+1]) total++;
                    if(i > 0 && up[i-1][j]) total++;
                    if(i < n - 1 && down[i+1][j]) total++;
                }
            }
        }
        return total;
    }
};