class Solution {
public:
    int maxPackages(vector<int>& arr, int totalTime) {
        int n = arr.size();

        // If totalTime is greater than the number of locations, 
        // the agent can visit all locations.
        if (totalTime >= n) {
            int totalSum = 0;
            for (int x : arr) totalSum += x;
            return totalSum;
        }

        // Use a sliding window of size `totalTime`
        int currentSum = 0;
        for (int i = 0; i < totalTime; i++) {
            currentSum += arr[i];
        }

        int maxSum = currentSum;

        // Slide the window across the array
        for (int i = totalTime; i < n; i++) {
            currentSum += arr[i] - arr[i - totalTime];
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};