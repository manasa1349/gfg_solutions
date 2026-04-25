class Solution {
  public:
  bool chk(int a,int b){
      return (a>=0 && b<0) || (a<0 && b>=0);
  }
    vector<int> reducePairs(vector<int>& arr) {
        // code here
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            bool op=false;
            while(!st.empty() && chk(arr[i],st.top())){
                if(abs(st.top())==abs(arr[i])){
                    st.pop();
                    op=true;
                    break;
                }else if(abs(st.top())<abs(arr[i])){
                    st.pop();
                }else{
                    op=true;
                    break;
                }
            }
            if(!op){
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