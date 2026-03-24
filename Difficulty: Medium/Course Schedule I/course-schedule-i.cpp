class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(n, 0);
        vector<vector<int>> adj(n);
        
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) q.push(i);
        }
        
        int count = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            count++;
            
            for (int nextCourse : adj[curr]) {
                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        
        return count == n;
    }
};