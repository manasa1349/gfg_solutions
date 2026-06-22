class Solution {
  public:
    int maxArea(vector<int> &arr) {
        // code here
        int n=arr.size();
        int l=0,r=n-1,ans=0;
        while(l<r){
            ans=max(ans,(min(arr[l],arr[r]))*(r-l-1));
            if(arr[l]<arr[r]){
                l++;
            }else{
                r--;
            }
        }
        return ans;
    }
};