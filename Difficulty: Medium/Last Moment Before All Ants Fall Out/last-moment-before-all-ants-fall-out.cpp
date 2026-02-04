class Solution {
  public:
    int getLastMoment(int n, vector<int>& l, vector<int>& r) {
        // code here
        int res=0;
        for(int i=0;i<l.size();i++){
            res=max(res,l[i]);
        }
        for(int i=0;i<r.size();i++){
            res=max(res,n-r[i]);
        }
        return res;
    }
};