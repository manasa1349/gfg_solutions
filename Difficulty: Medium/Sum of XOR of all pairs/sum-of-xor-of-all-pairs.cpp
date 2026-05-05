class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        long long sum=0;
        for(int i=0;i<32;i++){
            int zcnt=0,ocnt=0;
            //contribution=ones × zeros × 2^i
            for(int j=0;j<arr.size();j++){
                if((arr[j]>>i)&1){
                    zcnt++;
                }else{
                    ocnt++;
                }
            }
            sum+=(long)zcnt*ocnt*(1LL<<i);
        }
        return sum;
    }
};