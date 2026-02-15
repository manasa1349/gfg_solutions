class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        sort(a.begin(),a.end());
        //1 3 4 7 9 9 12 56
        int ans=a[m-1]-a[0];
        int l=1,r=m;
        while(r<a.size()){
            ans=min(ans,a[r]-a[l]);
            l++;
            r++;
        }
        return ans;
    }
};