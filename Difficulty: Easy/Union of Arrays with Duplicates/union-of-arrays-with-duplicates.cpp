class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        set<int>s(a.begin(),a.end());
        for(int i=0;i<b.size();i++){
            s.insert(b[i]);
        }
        vector<int>ans(s.begin(),s.end());
        return ans;
    }
};