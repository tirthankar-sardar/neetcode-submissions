class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 0){
                    q.push({row, col});
                }
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            auto[row, col] = q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < m 
                && ncol >= 0 && ncol < n
                && grid[nrow][ncol] == INT_MAX){
                    grid[nrow][ncol] = grid[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
};
