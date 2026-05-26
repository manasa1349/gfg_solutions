class Solution {
  public:
    int minToggle(vector<int>& arr) {
        // code here
        //ans= min(1 in left + 0 in right);
        int ones=accumulate(arr.begin(),arr.end(),0);
        if(ones==0) return 0;
        int zrs=0,ans=ones,n=arr.size();
        for(int i=n-1;i>=0;i--){
            ans=min(ans,ones+zrs);
            if(arr[i]==1){
                ones--;
            }
            if(arr[i]==0){
                zrs++;
            }
        }
        ans=min(ans,ones+zrs);
        return ans;
    }
};
