class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>> &vis){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
            && grid[nrow][ncol] == '1' 
            && !vis[nrow][ncol]){
                dfs(nrow, ncol, grid, vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col] == '1' && !vis[row][col]){
                    count++;
                    dfs(row, col, grid, vis);
                }
            }
        }
        return count;
    }
};
