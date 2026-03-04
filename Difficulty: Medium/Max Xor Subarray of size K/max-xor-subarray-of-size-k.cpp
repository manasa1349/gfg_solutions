class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int l=0,r=k,sum=0;
        for(int i=0;i<k;i++){
            sum^=arr[i];
        }
        int ans=sum;
        while(r<n){
            sum^=arr[l];
            sum^=arr[r];
            ans=max(ans,sum);
            l++;
            r++;
        }
        return ans;
    }
};
