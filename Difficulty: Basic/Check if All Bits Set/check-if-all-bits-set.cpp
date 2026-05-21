class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        if(n==0) return false;
        while(n){
            if(n%2!=1){
                return false;
            }
            n/=2;
        }
        return true;
    }
};