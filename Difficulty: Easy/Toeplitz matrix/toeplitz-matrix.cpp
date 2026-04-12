class Solution {
  public:
    bool func(int r,int c,int n,int m,vector<vector<int>>& mat){
        int i=r,j=c;
        int val=mat[r][c];
        while(i<n && j<m){
            if(mat[i][j]!=val){
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
    bool isToeplitz(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            if(!func(i,0,n,m,mat)){
                return false;
            }
        }
        for(int i=0;i<m;i++){
            if(!func(0,i,n,m,mat)){
                return false;
            }
        }
        return true;
    }
};