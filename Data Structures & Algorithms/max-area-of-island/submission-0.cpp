class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &vis){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int area = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
            && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                area += dfs(nrow, ncol, grid, vis);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col] == 1 && !vis[row][col]){
                    int currArea = dfs(row, col, grid, vis);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }
};