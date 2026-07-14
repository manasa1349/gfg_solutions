class Solution {
  public:
    int find(vector<int>& arr) {
        // code here
        // 28=16+(16-4)
        // newx=2*prevx-arr[i]
        //2*prevx-arr[i]>=need
        //prevx>=(need+arr[i])/2;
        int need=0;
        for(int i=arr.size()-1;i>=0;i--){
            need=(need+arr[i]+1)/2;
        }
        return (int)need;
    };
};