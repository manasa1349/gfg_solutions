class Solution {
  public:
    int setBitCount(int n){
        // int cnt=0;
        // while(n){
        //     if(n%2==1){
        //         cnt++;
        //     }
        //     n/=2;
        // }
        // return cnt;
        return __builtin_popcount(n);
    }
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
        stable_sort(arr.begin(),arr.end(),[this](int n1,int n2){
            return setBitCount(n1)>setBitCount(n2);
        });
        return arr;
    }
};