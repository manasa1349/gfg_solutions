class Solution {
  public:
    int maxFrequency(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int l=0,r=0,n=arr.size(),sum=0,ans=0;
        while(r<n){
            sum+=arr[r];
            int val=(arr[r]*(r-l+1))-sum;
            while(val>k){
                sum-=arr[l];
                l++;
                val=(arr[r]*(r-l+1))-sum;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};