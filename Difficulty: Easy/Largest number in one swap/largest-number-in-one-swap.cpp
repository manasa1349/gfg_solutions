class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n=s.size();
        vector<int>hash(10,-1);
        for(int i=0;i<n;i++){
            hash[s[i]-'0']=i;
        }
        for(int i=0;i<n;i++){
            int curr=s[i]-'0';
            for(int j=9;j>curr;j--){
                if(hash[j]>i){
                    swap(s[i],s[hash[j]]);
                    return s;
                }
            }
        }
        return s;
    }
};