class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        // code here
        vector<int>res;
        res.push_back(0);
        int val=0;
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==0){
                res.push_back(queries[i][1]^val);
            }else{
                val^=queries[i][1];
            }
        }
        for(int i=0;i<res.size();i++){
            res[i]^=val;
        }
        sort(res.begin(),res.end());
        return res;
    }
};
