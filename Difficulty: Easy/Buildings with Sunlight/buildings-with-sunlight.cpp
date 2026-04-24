class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        stack<int>st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<arr[i]){
                st.pop();
            }
            st.push(arr[i]);
        }
        return st.size();
    }
};