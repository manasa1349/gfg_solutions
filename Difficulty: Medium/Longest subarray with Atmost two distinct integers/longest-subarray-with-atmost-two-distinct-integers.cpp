class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        unordered_map<int,int>mp;
        int n=arr.size();
        int l=0,r=0,ans=0;
        while(r<n){
            mp[arr[r]]++;
            if(mp.size()>2){
                mp[arr[l]]--;
                if(mp[arr[l]]==0){
                    mp.erase(arr[l]);
                }
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};