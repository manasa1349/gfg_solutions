class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n=arr.size();
        int ans=0;
        vector<int>right(n),left(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            right[i]=st.empty()?n:st.top();
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            left[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            ans+=( ((right[i]-i) * (i-left[i])) * arr[i] );
        }
        return ans;
    }
};