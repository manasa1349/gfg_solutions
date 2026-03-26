class Solution {
  public:
    int maxDiff(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        int diff=0;
        for(int i=1;i<arr.size();i++){
            diff=max(diff,abs(arr[i]-arr[i-1]));
        }
        return diff;
    }
};