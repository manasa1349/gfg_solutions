class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n=arr.size(),ans=0;
        vector<int>pre(n);
        if(arr[0]>k){
            pre[0]=1;
        }else{
            pre[0]=-1;
        }
        for(int i=1;i<n;i++){
            if(arr[i]>k){
                pre[i]=pre[i-1]+1;
            }else{
                pre[i]=pre[i-1]-1;
            }
        } 
        unordered_map<int,int>mp;
        mp[0] = -1; 
        for(int i=0;i<n;i++){
            if(pre[i] > 0){
                ans = i + 1;
            }else if(mp.find(pre[i]-1)!=mp.end()){
                ans=max(ans,i-mp[pre[i]-1]);
            }
            
            if(mp.find(pre[i])==mp.end()){
                mp[pre[i]]=i;
            }
        }
        return ans;
    }
};