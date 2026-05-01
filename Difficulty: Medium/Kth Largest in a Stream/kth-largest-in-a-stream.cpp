class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
            if(pq.size()<k){
                ans.push_back(-1);
                continue;
            }
            if(pq.size()>k){
                pq.pop();
            }
            ans.push_back(pq.top());
        }
        return ans;
    }
};