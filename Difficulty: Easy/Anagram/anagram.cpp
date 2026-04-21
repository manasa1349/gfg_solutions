class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        unordered_map<char,int>mp;
        for(auto i:s1){
            mp[i]++;
        }
        for(auto i:s2){
            if(mp.find(i)==mp.end()){
                return false;
            }
            mp[i]--;
            if(mp[i]==0){
                mp.erase(i);
            }
        }
        return mp.size()==0;
    }
};