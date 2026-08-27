class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        // First pass: determine the next state
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int live = 0;

                // Count live neighbors
                for (int k = 0; k < 8; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= 0 && ni < m &&
                        nj >= 0 && nj < n) {

                        // 1 or -1 means originally alive
                        if (board[ni][nj] == 1 ||
                            board[ni][nj] == -1) {
                            live++;
                        }
                    }
                }

                // Live cell dies
                if (board[i][j] == 1) {
                    if (live < 2 || live > 3) {
                        board[i][j] = -1;
                    }
                }

                // Dead cell becomes alive
                else if (board[i][j] == 0) {
                    if (live == 3) {
                        board[i][j] = 2;
                    }
                }
            }
        }

        // Second pass: convert temporary states
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == -1)
                    board[i][j] = 0;

                else if (board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }
};