class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int rsum=0,lsum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            rsum+=arr[i];
        }
        for(int i=0;i<n;i++){
            lsum+=arr[i];
            rsum-=arr[i];
            if(lsum==rsum){
                return true;
            }
        }
        return false;
    }
};
