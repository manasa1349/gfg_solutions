class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int n=arr.size();
        int z=0,o=n-1,i=0;
        while(i<=o){
            if(arr[i]==0){
                swap(arr[i],arr[z]);
                z++;
                i++;
            }else{
                swap(arr[i],arr[o]);
                o--;
            }
        }
    }
};