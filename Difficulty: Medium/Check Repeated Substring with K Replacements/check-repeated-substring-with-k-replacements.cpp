class Solution {
  public:
    bool kSubstr(string &s, int k) {
        // code here
        unordered_map<string,int>mp;
        for(int i=0;i<s.size();i+=k){
            string str=s.substr(i,k);
            mp[str]++;
        }
        // cout<<mp.size();
        if(mp.size()>2) return false;
        if(mp.size()<=1) return true;
        int mn=INT_MAX;
        for(auto it:mp){
            mn=min(mn,it.second);
        }
        return mn<=1;
    }
};