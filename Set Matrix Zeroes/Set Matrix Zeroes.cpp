class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int x = -1 , y = -1;
        int n = (int)matrix.size () , m = (int)matrix[0].size ();
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                if (!matrix[i][j]) {
                    x = i;y = j;
                }
            }
        }
        if (x == -1) return ;
        for (int i = 0 ; i < n ; i ++) {
            if (matrix[i][y] == 0) matrix[i][y] = 1;
            else matrix[i][y] = 0;
        }
        for (int j = 0 ; j < m ; j ++) {
            if (matrix[x][j] == 0) matrix[x][j] = 1;
            else matrix[x][j] = 0;
        }
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                if (i != x && j != y && !matrix[i][j]) {
                    matrix[i][y] = matrix[x][j] = 1;
                }
            }
        }
        for (int i = 0 ; i < n ; i ++) {
            if (i != x && matrix[i][y]) {
                for (int j = 0 ; j < m ; j ++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 0 ; j < m ; j ++) {
            if (j != y && matrix[x][j]) {
                for (int i = 0 ; i < n ; i ++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 0 ; i < n ; i ++) {
            matrix[i][y] = 0;
        }
        for (int j = 0 ; j < m ; j ++) {
            matrix[x][j] = 0;
        }
    }
};