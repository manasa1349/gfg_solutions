class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        // code here.
        int res=1;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=res){
                res+=arr[i];
            }
        }
        return res;
    }
};