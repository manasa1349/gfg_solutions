class Solution {
  public:
    int maxi=INT_MIN;
    int maxSum(int n) {
        // code here.
        if(n<12) return n;
        return max(maxi,(maxSum(n/2)+maxSum(n/3)+maxSum(n/4)));
    }
};