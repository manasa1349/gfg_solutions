class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int,int>mp;
        int n=arr.size();
        int currxor=0;
        long res=0;
        for(int i=0;i<n;i++){
            currxor^=arr[i];
            if(currxor==k){
                res++;
            }
            if(mp.find(currxor^k)!=mp.end()){
                res+=mp[currxor^k];
            }
            mp[currxor]++;
        }
        return res;
    }
};
