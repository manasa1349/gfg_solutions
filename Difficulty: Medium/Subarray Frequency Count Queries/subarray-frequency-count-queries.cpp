class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        unordered_map<int,vector<int>>mp;
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int val=queries[i][2];
            if(mp.find(val)==mp.end()){
                ans.push_back(0);
                continue;
            }
            int lw_idx=lower_bound(mp[val].begin(),mp[val].end(),l)-mp[val].begin();
            int up_idx=upper_bound(mp[val].begin(),mp[val].end(),r)-mp[val].begin();
            ans.push_back(up_idx-lw_idx);
        }
        return ans;
    }
};