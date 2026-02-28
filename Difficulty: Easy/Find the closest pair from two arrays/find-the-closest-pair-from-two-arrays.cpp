class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
        int n1=arr1.size();
        int n2=arr2.size();
        int diff=INT_MAX;
        int a=0,b=0;
        int i=0,j=n2-1;
        while(i<n1 && j>=0){
            int val=arr1[i]+arr2[j];
            if(abs(val-x)<diff){
                diff=abs(val-x);
                a=arr1[i];
                b=arr2[j];
            }
            if(val<x){
                i++;
            }else{
                j--;
            }
        }
        // for(int i=0;i<n1;i++){
        //     for(int j=0;j<n2;j++){
        //         int val=abs(arr1[i]+arr2[j]-x);
        //         if(val<diff){
        //             diff=val;
        //             a=arr1[i];
        //             b=arr2[j];
        //         }
        //     }
        // }
        return {a,b};
    }
};