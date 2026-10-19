
class Solution {
public:
    int n;
    vector<int> state, res;

    bool dfs(int idx, vector<int>& arr) {
        if (idx < 0 || idx >= n)
            return true;

        if (state[idx] == 2)
            return res[idx];

        if (state[idx] == 1)
            return false;

        state[idx] = 1;

        int dest = idx + arr[idx];
        bool good = dfs(dest, arr);

        state[idx] = 2;
        res[idx] = good;

        return good;
    }

    int goodIndices(vector<int>& arr) {
        n = arr.size();
        state.assign(n, 0);
        res.assign(n, false);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (state[i] == 0)
                dfs(i, arr);

            if (res[i])
                ans++;
        }

        return ans;
    }
};
