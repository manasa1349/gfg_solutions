class Solution {
  public:
    int ans=0;
    int towerOfHanoi(int n, int from, int to, int aux) {
        if(n==0){
            return 0;
        }
        towerOfHanoi(n-1,from,aux,to);
        ans++;
        towerOfHanoi(n-1,aux,to,from);
        return ans;
    }
};