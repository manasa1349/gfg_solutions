class Solution {
  public:
    vector<int> optimalArray(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>res(n);
        res[0]=0;
        int sum=arr[0];
        for(int i=1;i<n;i++){
            sum+=abs(arr[i]);
            if(arr[0]!=arr[i]){
                int md=arr[i/2],val=0;
                res[i]=res[i-1]+abs(arr[i]-md);
            }
        }
        return res;
    }
};