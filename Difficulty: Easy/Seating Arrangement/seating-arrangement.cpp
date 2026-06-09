class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &arr) {
        // code here
        int n=arr.size(),cnt=0;
        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1] && arr[i]==1){
                return false;
            }
        }
        if(k==0) return true;
        for(int i=0;i<n;i++){
            if(i==0 && arr[i+1]!=1 && arr[i]!=1){
                cnt++;
                i++;
            }else if(i==n-1 && arr[i-1]!=1 && arr[i]!=1){
                cnt++;
                i++;
            }else if(arr[i-1]!=1 && arr[i+1]!=1 && arr[i]!=1){
                cnt++;
                i++;
            }
        }
        return cnt>=k;
    }
};
// 2
// 1 0 0 0 0