class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int ans=0,n=arr.size();
        //5 10 15 300
        int i=n-1;
        int j=n-2;
        while(j<i && i>=0 && j>=0){
            if(arr[i]-arr[j]>=k){
                i--;
                if(i==j){
                    j--;
                }
            }else if(arr[i]-arr[j]<k){
                ans+=(arr[j]+arr[i]);
                j-=2;
                i-=2;
            }
        }
        return ans;
    }
};