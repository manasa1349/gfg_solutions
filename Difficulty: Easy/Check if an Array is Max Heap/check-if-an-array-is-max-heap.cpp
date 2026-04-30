class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code here
        //2*i+1    2*i+2
        int n=arr.size();
        for(int i=0;i<=(n-2)/2;i++){
            if((2*i+1<n && arr[2*i+1]>arr[i]) || (2*i+2<n && arr[2*i+2]>arr[i])){
                return false;
            }
        }
        return true;
    }
};
