class Solution {
  public:
    bool isPower(int x, int y) {
        // code here
        if (x == 1) return y == 1;
        if (y == 1) return true;
        
        long long temp=x;
        while(temp<y){
            temp*=x;
        }
        return temp==y;
    }
};