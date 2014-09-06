class Solution {
public:
    bool isValidSudoku (vector<vector<char> > &board) {
        int row[9][9] , col[9][9] , block[9][9];
        memset (row , 0 , sizeof (row));
        memset (col , 0 , sizeof (col));
        memset (block , 0 , sizeof (block));
        for (int i = 0 ; i < 9 ; i ++) {
            for (int j = 0 ; j < 9 ; j ++) {
                if (board[i][j] == '.') continue;
                int ch = board[i][j] - '1';
                if (row[i][ch]) return false;
                if (col[ch][j]) return false;
                if (block[(i / 3) * 3 + j / 3][ch]) return false;
                row[i][ch] = col[ch][j] = block[(i / 3) * 3 + j / 3][ch] = 1;
            }
        }
        return true;
    }
    bool dfs (vector<vector<char> > &board) {
        for (int i = 0 ; i < 9 ; i ++) {
            for (int j = 0 ; j < 9 ; j ++) {
                if (board[i][j] == '.') {
                    for (char ch = '1' ; ch <= '9' ; ch ++) {
                        board[i][j] = ch;
                        if (isValidSudoku (board) && dfs (board)) return true;
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char> > &board) {
        dfs (board);
    }
};  