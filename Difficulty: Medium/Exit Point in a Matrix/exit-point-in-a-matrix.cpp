class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        // code here
        int i=0,j=0;
        int n=mat.size();
        int m=mat[0].size();
        int dir[2]={0,1};
        while(i<n && i>=0 && j<m && j>=0){
            if(mat[i][j]==1){
                mat[i][j]=0;
                if(dir[0] == 0 && dir[1] == 1){      // right -> down
                    dir[0] = 1;
                    dir[1] = 0;
                }
                else if(dir[0] == 1 && dir[1] == 0){ // down -> left
                    dir[0] = 0;
                    dir[1] = -1;
                }
                else if(dir[0] == 0 && dir[1] == -1){ // left -> up
                    dir[0] = -1;
                    dir[1] = 0;
                }
                else{ // up -> right
                    dir[0] = 0;
                    dir[1] = 1;
                }
            }
            i+=dir[0];
            j+=dir[1];
        }
        i-=dir[0];
        j-=dir[1];
        return {i,j};
    }
};