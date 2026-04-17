class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        unordered_map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        
        int o=0;
        for(auto i:mp){
            if(i.second%2!=0){
                o++;
            }
            if(o>1){
                return false;
            }
        }
        return true;
    }
};