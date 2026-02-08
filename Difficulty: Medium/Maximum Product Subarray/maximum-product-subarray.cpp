class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int pre=1,suf=1,n=arr.size(),ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(pre==0) pre=1;
            if(suf==0) suf=1;
            pre*=arr[i];
            suf*=arr[n-i-1];
            ans=max(ans,max(pre,suf));
        }
        return ans;
    }
    
};