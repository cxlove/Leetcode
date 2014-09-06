class Solution:
    # @param board, a 9x9 2D array
    # @return a boolean
    def isValidSudoku(self, board):
        row = [[False for i in range (9)] for j in range (9)]
        col = [[False for i in range (9)] for j in range (9)]
        block = [[False for i in range (9)] for j in range (9)]
        for i in range (9) :
            for j in range (9) :
                if board[i][j] == '.' : continue
                ch = ord (board[i][j]) - ord ('1')
                if row[i][ch] : return False
                if col[j][ch] : return False
                if block[(i / 3) * 3 + j / 3][ch] : return False
                row[i][ch] = col[j][ch] = block[(i / 3) * 3 + j / 3][ch] = True
        return True