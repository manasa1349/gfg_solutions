class Solution {
  public:
    string lexicographicallySmallest(string &s, int k) {
        // code here
        int n=s.size();
        vector<int>pow={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};
        bool chk=false;
        for(int i=0;i<pow.size();i++){
            if(pow[i]==n){
                k/=2;
                chk=true;
                break;
            }
        }
        if(!chk){
            k*=2;
        }
        
        if(k>=n) return "-1";
        
        stack<char>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && s[i]<st.top() && k>0){
                k--;
                st.pop();
            }
            st.push(s[i]);
        }
        while(k-- && !st.empty()){
            st.pop();
        }
        
        if(st.empty()) return "-1";
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};