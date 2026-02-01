class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int l=0,r=0,n=arr.size();
        vector<int>ans;
        deque<int> dq;
        while (r < k) {
            while (!dq.empty() && arr[dq.back()] <= arr[r])
                dq.pop_back();
            dq.push_back(r);
            r++;
        }
        ans.push_back(arr[dq.front()]);
        
        // now slide window with constant size
        while (r < n) {
            if (dq.front() == l)
                dq.pop_front();
            l++;
            while (!dq.empty() && arr[dq.back()] <= arr[r])
                dq.pop_back();
            dq.push_back(r);
            ans.push_back(arr[dq.front()]);
            r++;
        }
        return ans;
    }
};