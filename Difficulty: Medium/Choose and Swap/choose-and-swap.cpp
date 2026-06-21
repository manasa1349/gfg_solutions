class Solution {
  public:
    string chooseSwap(string &s) {
        // code here
        set<char>st;
        for(int i=0;i<s.size();i++){
            st.insert(s[i]);
        }
        for(int i=0;i<s.size();i++){
            st.erase(s[i]);
            if(st.empty()) break;
            char sml=*st.begin();
            
            if(sml<s[i]){
                char curr=s[i];
                
                for(int j=0;j<s.size();j++){
                    if(s[j]==curr) s[j]=sml;
                    else if(s[j]==sml) s[j]=curr;
                }
                break;
            }
        }
        return s;
    }
};
