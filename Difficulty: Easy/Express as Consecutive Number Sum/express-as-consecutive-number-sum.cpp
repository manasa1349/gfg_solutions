class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        // code here
        if(__builtin_popcount(n)==1)return false;
        return true;
    }
};