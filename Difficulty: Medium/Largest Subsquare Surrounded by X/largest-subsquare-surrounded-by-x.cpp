#include <vector>
#include <algorithm>

class Solution {
public:
    int largestSubsquare(std::vector<std::vector<char>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;

        std::vector<std::vector<int>> hor(n, std::vector<int>(n, 0));
        std::vector<std::vector<int>> ver(n, std::vector<int>(n, 0));

        // Precompute horizontal and vertical counts of 'X'
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 'X') {
                    hor[i][j] = (j == 0) ? 1 : hor[i][j - 1] + 1;
                    ver[i][j] = (i == 0) ? 1 : ver[i - 1][j] + 1;
                }
            }
        }

        int max_size = 0;

        // Check for the largest square ending at (i, j)
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int k = std::min(hor[i][j], ver[i][j]);

                // Reduce k if top or left side does not have enough 'X's
                while (k > max_size) {
                    if (ver[i][j - k + 1] >= k && hor[i - k + 1][j] >= k) {
                        max_size = k;
                        break;
                    }
                    k--;
                }
            }
        }

        return max_size;
    }
};