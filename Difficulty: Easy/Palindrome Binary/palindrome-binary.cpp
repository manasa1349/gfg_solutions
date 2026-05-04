class Solution {
  public:
    vector<int>bin;
    bool isBinaryPalindrome(int n) {
        // code here
        while(n){
            bin.push_back(n%2);
            n/=2;
        }
        n=bin.size();
        for(int i=0;i<n/2;i++){
            if(bin[i]!=bin[n-i-1]){
                return false;
            }
        }
        return true;
    }
};