class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        int n=s1.size();
        unordered_map<char,char>mp,mpp;
        for(int i=0;i<n;i++){
            if(mp[s1[i]] && mp[s1[i]]!=s2[i]) return false;
            if(mpp[s2[i]] && mpp[s2[i]]!=s1[i]) return false;
            mp[s1[i]]=s2[i];
            mpp[s2[i]]=s1[i];
        }
        return true;
    }
};