class Solution {
  public:
    void func(int l,int r,long long low,long long high,vector<int>&vis,vector<int>&arr){
        if(l>r) return;
        int mid=floor((l+r)/2);
        if(arr[mid] > low && arr[mid] < high){
            vis[mid]=1;
        }
        func(l,mid-1,low, min(high,(long long)arr[mid]),vis,arr);
        func(mid+1,r,max(low, (long long)arr[mid]),high,vis,arr);
    }
    int binarySearchable(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>vis(n);
        int l=0;
        int r=n-1;
        func(l,r,LLONG_MIN,LLONG_MAX,vis,arr);
        return accumulate(vis.begin(),vis.end(),0);
    }
};