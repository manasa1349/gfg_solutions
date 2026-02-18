class Solution {
  public:
    long long ans=0;
    void merge(vector<int>&arr,int l,int m,int h){
          int i=l,j=m+1,k=0;
          vector<int>res(h-l+1);
          while(i<=m && j<=h){
              if(arr[i]<=arr[j]){
                  res[k++]=arr[i];
                  i++;
              }else{
                  ans+=m-i+1;
                  res[k++]=arr[j];
                  j++;
              }
          }
          while(i<=m){
              res[k++]=arr[i];
              i++;
          }
          while(j<=h){
              res[k++]=arr[j];
              j++;
          }
          k=0;
          for(i=l;i<=h;i++){
              arr[i]=res[k];
              k++;
          }
    }
    void mergeSort(vector<int>&arr,int l,int h){
        if(l<h){
            int m=(l+h)/2;
            mergeSort(arr,l,m);
            mergeSort(arr,m+1,h);
            merge(arr,l,m,h);
        }
        
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        mergeSort(arr,0,arr.size()-1);
        return ans;
    }
};
