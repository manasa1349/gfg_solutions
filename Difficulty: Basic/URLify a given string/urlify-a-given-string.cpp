class Solution {
  public:
    string URLify(string &s) {
        // code here
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]==' ')cnt++;
        }
        if(cnt==0){
            return s;
        }
        int new_n=n+(cnt*2);
        s.resize(new_n);
        int idx=new_n-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]==' '){
                s[idx--]='0';
                s[idx--]='2';
                s[idx--]='%';
            }else{
                s[idx--]=s[i];
            }
        }
        return s;
    }
};