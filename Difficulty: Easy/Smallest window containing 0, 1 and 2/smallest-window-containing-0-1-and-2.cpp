class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
        int l=0,r=0,n=s.size();
        int ans=INT_MAX;
        unordered_map<char,int>mp;
        while(r<n){
            mp[s[r]]++;
            while(mp.size()==3){
                ans=min(ans,r-l+1);
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            r++;
        }
        return ans==INT_MAX?-1:ans;
    }
};
