class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
        // sort(arr.begin(),arr.end());
        int n=arr.size();
        int idx=lower_bound(arr.begin(),arr.end(),k)-arr.begin();
        if(idx>n-1 || arr[idx]!=k){
            return -1;
        }
        return idx;
    }
};