class Solution {
  public:
    int optimalKeys(int n) {
        // code here
        if(n <= 6){
            return n;
        }
        int screen[n];
        for(int i = 1; i <= 6; i++){
            screen[i - 1] = i;
        }
        for(int i = 7; i <= n; i++) {
            screen[i - 1] = 0;
            for (int b = i - 3; b >= 1; b--) {
                int curr = (i - b - 1) * screen[b - 1];
                if (curr > screen[i - 1])
                    screen[i - 1] = curr;
            }
        }
        return screen[n - 1];
    }
};
