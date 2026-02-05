class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int l=0,r=0;
        int n=arr.size();
        int cnt=0,ans=0;
        while(r<n){
            if(arr[r]==0){
                cnt++;
            }
            if(cnt>k && l<=r){
                if(arr[l]==0){
                    cnt--;
                }
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
