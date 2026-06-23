class Solution {
  public:
    bool func(int mid,int p){
        for(int i=1;i<=mid;i++){
            if(i*i<=p){
                p-=(i*i);
            }else{
                return false;
            }
        }
        return true;
        // long long sum = n * (n + 1) * (2 * n + 1) / 6;
        // return sum <= p;
    }
    int maxPeopleDefeated(int p) {
        // Code Here
        int l=0,r=sqrt(p),ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(func(mid,p)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};
