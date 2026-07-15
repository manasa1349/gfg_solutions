class Solution {
  public:
    int bitonic(vector<int> &arr) {
        // code here
        int ans=0,n=arr.size();
        vector<int>inc(n),dec(n);
        inc[0]=0;
        dec[n-1]=n-1;
        for(int i=1;i<n;i++){
            if(arr[i-1]<=arr[i]){
                inc[i]=inc[i-1];
            }else{
                inc[i]=i;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=arr[i+1]){
                dec[i]=dec[i+1];
            }else{
                dec[i]=i;
            }
        }
        
        for(int i=0;i<n;i++){
            ans=max(ans,dec[i]-inc[i]+1);
        }
        return ans;
    }
};