class Solution {
  public:
    int minSquares(int n, int m) {
        // code here
        int ans=0;
        while(n>0 || m>0){
            if(n==1){
                ans+=m;
                return ans;
            }else if(m==1){
                ans+=n;
                return ans;
            }
            int mn=min(n,m);
            int mx=max(n,m);
            if(mx==mn){
                ans+=1;
                return ans;
            }
            ans+=1;
            mx-=mn;
            m=mx;
            n=mn;
        }
        return ans;
    }
};