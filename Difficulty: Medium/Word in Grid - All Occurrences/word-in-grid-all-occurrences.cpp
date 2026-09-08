class Solution {
  public:
    bool validcoord(int x,int y,int r,int c){
        if(x>=0 && x<r && y>=0 && y<c){
            return true;
        }
        return false;
    }
    bool findword(int idx,string &word,vector<vector<char>>&mat,int i,int j,
        int diri,int dirj,int r,int c){
        if(idx==word.size()){
            return true;
        }
        if(validcoord(i,j,r,c) && word[idx]==mat[i][j]){
            return findword(idx+1,word,mat,i+diri,j+dirj,diri,dirj,r,c);
        }
        return false;
    }
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        // Code here
        int r=mat.size();
        int c=mat[0].size();
        vector<vector<int>>res;
        int dirx[]={-1,-1,-1,0,0,1,1,1};
        int diry[]={-1,0,1,-1,1,-1,0,1};
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                for(int k=0;k<8;k++){
                    if(findword(0,word,mat,i,j,dirx[k],diry[k],r,c)){
                        res.push_back({i,j});
                        break;
                    }
                }
            }
        }
        return res;
    }
};