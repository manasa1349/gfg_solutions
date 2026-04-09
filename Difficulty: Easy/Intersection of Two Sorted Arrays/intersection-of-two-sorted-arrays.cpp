class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,int>mp;
        vector<int>ans;
        for(auto i:a){
            mp[i]++;
        }
        for(int i=0;i<b.size();i++){
            if(mp.find(b[i])!=mp.end()){
                ans.push_back(b[i]);
                mp.erase(b[i]);
            }
        }
        return ans;
    }
};