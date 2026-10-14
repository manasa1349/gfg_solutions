class Solution {
  public:
    string findRollOut(string& s, vector<int>& roll) {
        // code here
        int n=s.size();
        vector<int>pre(n,0);
        for(int i:roll){
            pre[i-1]++;
        }
        for(int i=n-2;i>=0;i--){
            pre[i]+=pre[i+1];
        }
        for(int i=0;i<n;i++){
            int val=(pre[i])%26;
            s[i] = 'a' + (s[i]-'a'+val)%26;
        }
        return s;
    }
};
