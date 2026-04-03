class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        // code here
        //(0,0)
        //(0,1) , (1,0)               so i+1,j-1
        //(0,2) , (1,1) , (2,0)     
        //for above format is (0,0->n-1) and then i++,j--
        
        //(1,2) , (2,1)
        //(2,2)
        //for above start is (1->n-1,n-1)
        vector<int>ans;
        int n=mat.size();
        for(int idx=0;idx<n;idx++){
            int i=0,j=idx;
            while(i<n && j>=0){
                ans.push_back(mat[i][j]);
                i++;
                j--;
            }
        }
        for(int idx=1;idx<n;idx++){
            int i=idx,j=n-1;
            while(i<n && j>=0){
                ans.push_back(mat[i][j]);
                i++;
                j--;
            }
        }
        return ans;
    }
};