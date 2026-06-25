class Solution {
  public:
    void func(int n,vector<int>&ans,int ds,int sz){
        if(sz==n){
            ans.push_back(ds);
            return;
        }
        int val=ds%10;
        for(int i=val+1;i<=9;i++){
            func(n,ans,ds*10+i,sz+1);
        }
    }
    vector<int> increasingNumbers(int n) {
        // code here
        vector<int>ans;
        if(n==1){
            for(int i=0;i<=9;i++){
                ans.push_back(i);
            }
            return ans;
        }
        for(int i=1;i<=9;i++){
            func(n,ans,i,1);
        }
        return ans;
    }
};