class Solution {
public:
    int n;
    const int MOD = 1e9 + 7;

    vector<vector<pair<int, int>>> dp;
    vector<vector<bool>> vis;

    pair<int, int> solve(int r, int c, vector<vector<int>>& grid) {

        // Destination
        
        if (r == n - 1 && c == n - 1) {
            return {1, grid[r][c]};
        }

        // Same as @cache
        if (vis[r][c]) {
            return dp[r][c];
        }

        vis[r][c] = true;

        int paths = 0;
        int maxadv = 0;

        // Move right
        if (grid[r][c] == 1 || grid[r][c] == 3) {
            if (c + 1 < n) {
                auto [p, adv] = solve(r, c + 1, grid);

                paths += p;
                maxadv = max(maxadv, adv);
            }
        }

        // Move down
        if (grid[r][c] == 2 || grid[r][c] == 3) {
            if (r + 1 < n) {
                auto [p, adv] = solve(r + 1, c, grid);

                paths += p;
                maxadv = max(maxadv, adv);
            }
        }

        // No valid path
        if (paths == 0) {
            return dp[r][c] = {0, 0};
        }

        maxadv += grid[r][c];

        return dp[r][c] = {paths % MOD, maxadv};
    }

    vector<int> findWays(vector<vector<int>>& grid) {

        n = grid.size();

        dp.assign(n, vector<pair<int, int>>(n));
        vis.assign(n, vector<bool>(n, false));

        auto [paths, maxadv] = solve(0, 0, grid);

        return {paths, maxadv};
    }
};