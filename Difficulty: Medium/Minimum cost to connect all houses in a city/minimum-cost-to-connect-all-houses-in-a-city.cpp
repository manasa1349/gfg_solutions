class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n = houses.size();
        if (n == 0) return 0;

        // minDist[i] stores the minimum cost to connect house i to the growing MST
        vector<int> minDist(n, INT_MAX);
        // visited[i] tracks if house i is already included in our MST
        vector<bool> visited(n, false);
        
        int totalCost = 0;
        int edgesConnected = 0;
        
        // Start with the first house (index 0)
        minDist[0] = 0;

        while (edgesConnected < n) {
            int currHouse = -1;
            int minWeight = INT_MAX;

            // 1. Pick the unvisited house with the smallest distance to the MST
            for (int i = 0; i < n; ++i) {
                if (!visited[i] && minDist[i] < minWeight) {
                    minWeight = minDist[i];
                    currHouse = i;
                }
            }

            // 2. Add this house to the MST
            visited[currHouse] = true;
            totalCost += minWeight;
            edgesConnected++;

            // 3. Update distances from the newly added house to all other unvisited houses
            for (int nextHouse = 0; nextHouse < n; ++nextHouse) {
                if (!visited[nextHouse]) {
                    // Calculate Manhattan Distance
                    int cost = abs(houses[currHouse][0] - houses[nextHouse][0]) + 
                               abs(houses[currHouse][1] - houses[nextHouse][1]);
                    
                    // If this new connection is cheaper than what we found before, update it
                    if (cost < minDist[nextHouse]) {
                        minDist[nextHouse] = cost;
                    }
                }
            }
        }

        return totalCost;
    }
};