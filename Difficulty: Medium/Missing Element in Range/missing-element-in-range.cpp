class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        sort(arr.begin(),arr.end());
        int st=lower_bound(arr.begin(),arr.end(),low)-arr.begin();
        int ed=upper_bound(arr.begin(),arr.end(),high)-arr.begin();
        //10 11 12 15
        //st          up
        set<int>s;
        for(int i=low;i<=high;i++){
            s.insert(i);
        }
        for(int i=st;i<ed;i++){
            s.erase(arr[i]);
        }
        vector<int>ans(s.begin(),s.end());
        return ans;
    }
};