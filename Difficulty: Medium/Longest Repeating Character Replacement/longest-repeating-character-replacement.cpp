class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        int l=0,r=0,n=s.size();
        int ans=INT_MIN,maxFreq=0;
        unordered_map<char,int>mp;
        while(r<n){
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);
            while((r-l+1)-maxFreq>k){
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans==INT_MIN?-1:ans;
    }
};