class Solution {
  public:
    int majorityElement(vector<int>& a) {
        // code here
        int cand = a[0], c = 1 , n=a.size();

        // Phase 1: Find candidate
        for (int i = 1; i < n; i++) {
            if (a[i] == cand) c++;
            else c--;
    
            if (c == 0) {
                cand = a[i];
                c = 1;
            }
        }
    
        // Phase 2: Verify candidate
        c = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == cand) c++;
        }
    
        return (c > n / 2) ? cand : -1;
    }
};