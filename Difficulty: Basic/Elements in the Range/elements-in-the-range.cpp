class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        int cnt=end-start+1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=start && arr[i]<=end){
                cnt--;
            }
        }
        return cnt==0;
    }
};
