class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        int n=s.size(),ans=-1;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=i;
            }else{
                ans=max(ans,i-mp[s[i]]-1);
            }
        }
        return ans;
    }
};