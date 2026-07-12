class Solution {
  public:
    const long long MOD=1e9+7;
    int maxAmount(vector<int>& arr, int k) {
        // code here
        priority_queue<long long>pq(arr.begin(),arr.end());
        long long ans=0;
        while(!pq.empty() && k--){
            long long val=pq.top();
            ans=(ans+val)%MOD;
            pq.pop();
            if(val>1){
                pq.push(val-1);
            }
        }
        return (int)ans;
    }
};