int coin(int arr[], int n) {
    // code here
    int l=0,r=n-1;
    while(l<r){
        if(arr[l]<arr[r]){
            r--;
        }else{
            l++;
        }
    }
    return arr[l];
}