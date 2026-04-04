class Solution {
  public:
    vector<string>ans;
    //"" (rev = F)
    // ├── "0" (rev = F)
    // │   ├── "00" (rev = F)
    // │   │   ├── "000" 
    // │   │   └── "001"
    // │   └── "01" (rev = T)
    // │       ├── "011" 
    // │       └── "010" 
    // └── "1" (rev = T)
    //     ├── "11" (rev = F)
    //     │   ├── "110" 
    //     │   └── "111" 
    //     └── "10" (rev = T)
    //         ├── "101" 
    //         └── "100" 
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