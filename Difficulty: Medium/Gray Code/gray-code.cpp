class Solution {
  public:
    vector<string>ans;
    void func(string ds,int n,bool rev){
        if(ds.size()==n){
            ans.push_back(ds);
            return;
        }
        if (!rev) {
            func(ds + '0', n, false);
            func(ds + '1', n, true);
        } else {
            func(ds + '1', n, false);
            func(ds + '0', n, true);
        }
    }
    vector<string> graycode(int n) {
        // code here
        func("",n,false);
        return ans;
    }
};