class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board){
        int m = board.size();
        int n = board[0].size();
        board[row][col] = 'T';
        int drow[] = {-1,1,0,0};
        int dcol[] = {0,0,-1,1};

        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < m
            && ncol >= 0 && ncol < n
            && board[nrow][ncol] == 'O'){
                dfs(nrow, ncol, board);
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        //checking the first and the last column
        for(int i=0; i<m; i++){
            if(board[i][0] == 'O'){
                dfs(i, 0, board);
            }
            if(board[i][n-1] == 'O'){
                dfs(i, n-1, board);
            }
        }

        //checking the first and the last row
        for(int j=0; j<n; j++){
            if(board[0][j] == 'O'){
                dfs(0, j, board);
            }
            if(board[m-1][j] == 'O'){
                dfs(m-1, j, board);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};