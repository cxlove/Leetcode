class NumMatrix {
public:
    vector<vector<int> > sum;
    NumMatrix(vector<vector<int> > &matrix) {
        int n = (int)matrix.size () , m = 0;
        if (!matrix.empty ())  m = (int)matrix[0].size ();
        sum.resize (n + 1 , vector <int> (m + 1 , 0));
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);