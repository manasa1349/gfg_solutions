class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>>q;
        vector<int>vis(1001,0);
        q.push({start,0});
        vis[start]=1;
        while(!q.empty()){
            int val=q.front().first;
            int cnt=q.front().second;
            if(val==end){
                return cnt;
            }
            q.pop();
            for(int i=0;i<arr.size();i++){
                int k=val*arr[i]%1000;
                if(!vis[k]){
                    q.push({k,cnt+1});
                    vis[k]=1;
                }
            }
        }
        return -1;
    }
};