class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        // code here
        vector<pair<int,int>>arr;
        int n=a.size();
        for(int i=0;i<n;i++){
            arr.push_back({abs(a[i]-b[i]),i});
        }
        
        sort(arr.begin(),arr.end(),greater());
        
        int i=0,ans=0;
        while(i<n && x>0 && y>0){
            int idx=arr[i].second;
            if(a[idx]>=b[idx]){
                ans+=a[idx];
                x--;
            }else{
                ans+=b[idx];
                y--;
            }
            i++;
        }
        while(i<n && x>0){
            int idx=arr[i].second;
            ans+=a[idx];
            x--;
            i++;
        }
        while(i<n && y>0){
            int idx=arr[i].second;
            ans+=b[idx];
            y--;
            i++;
        }
        return ans;
    }
};