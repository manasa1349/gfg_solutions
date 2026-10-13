class Solution {
  public:
    vector<int> update(int n, vector<int>& updates) {
        // code here
        vector<int>pre(n,0);
        for(int i=0;i<updates.size();i++){
            pre[updates[i]-1]++;
        }
        for(int i=1;i<n;i++){
            pre[i]+=pre[i-1];
        }
        return pre;
    }
};