class Solution {
  public:
    bool chk(int a,int b){
        return (a>=0 && b>=0) || (a<0 && b<0);
    }
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            if(!st.empty() && !chk(st.top(),arr[i])){
                st.pop();
            }else{
                st.push(arr[i]);
            }
        }
        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};