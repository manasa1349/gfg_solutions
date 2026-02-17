class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
        int n=arr[0][1];
        for(int i=1;i<arr.size();i++){
            n=max(n,arr[i][1]);
        }
        vector<long long>pre(n+2);
        for(int i=0;i<arr.size();i++){
            long long a=arr[i][0];
            long long b=arr[i][1];
            pre[a]+=1;
            pre[b+1]-=1;
        }
        long long ans=pre[0];
        for(int i=1;i<pre.size();i++){
            pre[i]+=pre[i-1];
            ans=max(ans,pre[i]);
        }
        return (int)ans;
    }
};
