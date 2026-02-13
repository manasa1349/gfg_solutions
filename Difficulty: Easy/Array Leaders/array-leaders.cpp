

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        stack<int>st;
        vector<int>res;
        int n=arr.size();
        st.push(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=st.top()){
                st.push(arr[i]);
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        // reverse(res.begin(),res.end());
        return res;
    }
};