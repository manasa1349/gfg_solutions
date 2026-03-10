class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        stack<int>st;
        int n=arr.size(),ans=0;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            int r = st.empty() ? n : st.top();
            ans+=r-i;            
            st.push(i);
        }
        return ans;
    }
};