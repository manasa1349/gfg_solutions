class Solution {
  public:
    bool isPossible(int n, int m, string& s) {
        // code here
        int mxr=0,mnr=0,mxc=0,mnc=0,r=0,c=0;
        for(auto i:s){
            if(i=='L'){
                c--;
            }else if(i=='R'){
                c++;
            }else if(i=='U'){
                r--;
            }else if(i=='D'){
                r++;
            }
            mxr=max(mxr,r);
            mnr=min(mnr,r);
            mxc=max(mxc,c);
            mnc=min(mnc,c);
        }
        if(mxr-mnr+1>n || mxc-mnc+1>m) return false;
        return true;
    }
};