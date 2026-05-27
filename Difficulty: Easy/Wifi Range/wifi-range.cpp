class Solution {
  public:
    bool wifiRange(string &arr, int x) {
        // code here
        int n=arr.size();
        vector<int>pre(n+1,0);
        
        for(int i=0;i<n;i++){
            if(arr[i]=='1'){
                int lidx=max(0,i-x);
                pre[lidx]+=1;
                int ridx=i+x+1;
                if(ridx<n){
                    pre[ridx]-=1;
                }else{
                    pre[n]-=1;
                }
            }
        }
        for(int i=1;i<n;i++){
            pre[i]=pre[i]+pre[i-1];
        }
        
        for(int i=0;i<n;i++){
            if(pre[i]<=0){
                return false;
            }
        }
        return true;
    }
};