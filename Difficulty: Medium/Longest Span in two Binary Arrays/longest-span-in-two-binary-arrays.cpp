class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        // code here
        int n=a1.size();
        int ans=0;
        vector<int>pre(n);
        pre[0]=a1[0]-a2[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+(a1[i]-a2[i]);
        }
        unordered_map<int,int>mp;
        mp[0] = -1; 
        for(int i=0;i<n;i++){
            if(mp.find(pre[i])!=mp.end()){
                ans=max(ans,i-mp[pre[i]]);
            }else{
                mp[pre[i]]=i;
            }
        }
        return ans;
    }
};