class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        // Code here
        int n=arr.size();
        vector<int>arr1(arr.begin(),arr.begin()+(n/2));
        vector<int>arr2(arr.begin()+(n/2),arr.end());
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        
        int ans=0,j=0;
        for(int i=0;i<n/2;i++){
            while(j<n/2 && arr1[i]>=5*arr2[j]){
                j++;
            }
            ans+=j;
        }
        return ans;
    }
};