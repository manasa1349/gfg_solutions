class Solution {
  public:
    int findPosition(int n) {
        // code here
        if(n==1) return 1;
        if(n%2!=0) return -1;
        //val 1 2 4 8 16 18
        //pos 1 2 3 4  5  6
        int val=1,cnt=1;
        while(val<=n){
            val*=2;
            cnt++;
            if(n==val){
                return cnt;
            }
        }
        return -1;
    }
};