class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        // code here
        int sm=accumulate(arr.begin(),arr.end(),0);
        int lsum=0;
        for(int i=0;i<arr.size();i++){
            sm-=arr[i];
            if(sm==lsum){
                return i;
            }
            lsum+=arr[i];
        }
        return -1;
    }
};