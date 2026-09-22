class Solution {
  public:
    string findLongestWord(string &s, vector<string> &d) {
        // code here
        sort(d.begin(),d.end(),[](auto &s1, auto &s2){
            if(s1.size()==s2.size()){
                return s1<s2;
            }
            return s1.size()>s2.size();
        });
        string ans="";
        int mxcnt=0;
        for(string &st:d){
            int l=0,r=0,n1=st.size(),n2=s.size();
            while(l<n1 && r<n2){
                if(st[l]==s[r]){
                    l++;
                    r++;
                }else{
                    r++;
                }
            }
            if(l==n1){
                return st;
            }
        }
        return ans;
    }
};