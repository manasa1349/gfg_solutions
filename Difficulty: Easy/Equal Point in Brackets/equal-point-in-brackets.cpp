class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int lcnt=0,rcnt=0,n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                rcnt++;
            }
        }
        for(int i=0;i<=n;i++){
            if(rcnt==lcnt){
                return i;
            }
            if(i<n){
                if(s[i]=='('){
                    lcnt++;
                }else if(s[i]==')'){
                    rcnt--;
                }
            }
        }
        return -1;
    }
};