class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int n=arr.size();
        int ans=0,cnt=0;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                cnt++;
                ans+=cnt;
            }else{
                cnt=0;
            }
        }
        return ans;
    }
};
