class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        // code here
        int ans=0,z=0,o=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1){
                z--;
                o++;
            }else{
                z++;
            }
            if(z<0) z=0;
            ans=max(ans,z);
        }
        return ans+o;
    }
};