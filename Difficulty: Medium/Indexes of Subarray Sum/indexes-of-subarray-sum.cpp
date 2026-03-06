class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        //1 2 3 7  5
        //1 3 6 13 18
        int n=arr.size();
        int sum=0;
        int j=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            while (sum > target && j <= i) {
                sum-=arr[j];
                j++;
            }
            if(sum==target){
                return {j+1,i+1};
            }
        }
        return {-1};
    }
};
