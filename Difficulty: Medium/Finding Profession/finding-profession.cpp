class Solution {
  public:
    string profession(int level, int pos) {
        // code here
        //totl nodes in level is 2^(n-1)
        //left/right half  (2^(n-1))/2
        if (__builtin_popcount(pos - 1) % 2)
            return "Doctor";
        return "Engineer";
        
    }
};