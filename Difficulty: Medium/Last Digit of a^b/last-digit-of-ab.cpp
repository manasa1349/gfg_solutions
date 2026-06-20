class Solution {
  public:
    int getLastDigit(string& aa, string& bb) {
        // code 
        int a=aa.back()-'0';
        if(bb=="0") return 1;
        int ans=1,b=0;
        for(int i=0;i<bb.size();i++){
            b=((b*10)+(bb[i]-'0'))%4;
        }
        if(b==0) b=4;
        for(int i=0;i<b;i++){
            ans=(ans*a)%10;
        }
        return ans;
    }
};