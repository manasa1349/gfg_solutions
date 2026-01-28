class Solution {
  public:
    void func(vector<int>&arr,int idx,int end,int k,vector<long long>&res,int sum){
        if(idx>=end){
            res.push_back(sum);
            return;
        }
        func(arr,idx+1,end,k,res,sum);
        func(arr,idx+1,end,k,res,sum+arr[idx]);
    }
    int countSubset(vector<int> &arr, int k) {
        // code here
        int mid=(arr.size())/2;
        int sum=0,cnt=0;
        vector<long long>ls,rs;
        func(arr,0,mid,k,ls,0);
        func(arr,mid,arr.size(),k,rs,sum);
        sort(rs.begin(),rs.end());
        for(int i=0;i<ls.size();i++){
            int need=k-ls[i];
            cnt+= upper_bound(rs.begin(),rs.end(),need)
                - lower_bound(rs.begin(),rs.end(),need);
        }
        return cnt;
    }
};