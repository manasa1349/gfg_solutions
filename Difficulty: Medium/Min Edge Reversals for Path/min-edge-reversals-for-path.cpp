class Solution {
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int des) {
        // code here  
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back({0,v}); //original edge
            adj[v].push_back({1,u}); //reversed edge
        }
        
        //dijkistra's algo to find shortest weighted way from src to des
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
        q.push({0,src}); //dist node
        dist[src]=0;
        while(!q.empty()){
            int dis=q.top().first;
            int node=q.top().second;
            q.pop();
            if(dis>dist[node]){
                continue;
            }
            for(auto &it:adj[node]){
                if(dis+it.first < dist[it.second]){
                    dist[it.second]=dis+it.first;
                    q.push({dist[it.second],it.second});
                }
            }
        }
        return dist[des]==INT_MAX?-1:dist[des];
    }
};