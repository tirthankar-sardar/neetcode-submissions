class Solution {
public:
    void dfs(int row, int col,
             vector<vector<int>>& heights,
             vector<vector<int>>& vis) {

        vis[row][col] = 1;

        int m = heights.size();
        int n = heights[0].size();

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = row + dr[k];
            int nc = col + dc[k];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                vis[nr][nc] == 0 &&
                heights[nr][nc] >= heights[row][col]) {

                dfs(nr, nc, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        if (heights.empty() || heights[0].empty()) {
            return {};
        }

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        // Pacific: top row
        for (int j = 0; j < n; j++) {
            if (pacific[0][j] == 0) {
                dfs(0, j, heights, pacific);
            }
        }

        // Pacific: left column
        for (int i = 0; i < m; i++) {
            if (pacific[i][0] == 0) {
                dfs(i, 0, heights, pacific);
            }
        }

        // Atlantic: bottom row
        for (int j = 0; j < n; j++) {
            if (atlantic[m - 1][j] == 0) {
                dfs(m - 1, j, heights, atlantic);
            }
        }

        // Atlantic: right column
        for (int i = 0; i < m; i++) {
            if (atlantic[i][n - 1] == 0) {
                dfs(i, n - 1, heights, atlantic);
            }
        }

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] == 1 &&
                    atlantic[i][j] == 1) {

                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};