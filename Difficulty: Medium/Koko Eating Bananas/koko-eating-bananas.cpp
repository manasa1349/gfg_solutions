class Solution {
  public:
    bool check(vector<int>& arr, int speed, int k) {
        long long hours = 0;
        for (int bananas : arr) {
            hours += (bananas + speed - 1) / speed;
            if (hours > k) return false;
        }
        return true;
    }

    int kokoEat(vector<int>& arr, int k) {
        // Code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int l=1,h=arr[n-1],res=arr[n-1];
        while(l<=h){
            int m=(l+h)/2;
            if(check(arr,m,k)){
                res=m;
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return res;
    }
};