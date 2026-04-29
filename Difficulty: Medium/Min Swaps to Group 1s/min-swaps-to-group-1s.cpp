class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // code here
        int n=arr.size();
        int o=0,z=0,l=0,r=0;
        for(auto i:arr){
            if(i==1) o++;
        }
        if(o==0) return -1;
        
        int currOnes = 0;
        for(int i = 0; i < o; i++) {
            currOnes += arr[i];
        }
        
        int maxOnes = currOnes;
        for(int i = o; i < n; i++) {
            currOnes += arr[i] - arr[i - o];
            maxOnes = max(maxOnes, currOnes);
        }
        
        return o - maxOnes;

    }
};