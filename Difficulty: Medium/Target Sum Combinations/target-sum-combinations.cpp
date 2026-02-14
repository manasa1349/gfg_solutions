class Solution {
  public:
    void func(int idx,int tar,vector<int>arr,vector<vector<int>>&ans,vector<int>&ds){
        if(tar==0){
            ans.push_back(ds);
            return;
        }
        for(int i=idx;i<arr.size();i++){
            if(arr[i]>tar) break;
            ds.push_back(arr[i]);
            func(i,tar-arr[i],arr,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        // code here
        vector<vector<int>>ans;
        vector<int>ds;
        sort(arr.begin(),arr.end());
        func(0,target,arr,ans,ds);
        return ans;
    }
};