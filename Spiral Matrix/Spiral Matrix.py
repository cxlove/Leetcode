class Solution:
    # @param matrix, a list of lists of integers
    # @return a list of integers
    def spiralOrder(self, matrix):
        if len (matrix) == 0 : return []
        n , m = len (matrix) , len (matrix[0])
        l = 0
        r = m - 1
        u = 0
        d = n - 1
        ans = []
        while l <= r and u <= d :
            for i in range (l , r + 1) :
                ans.append (matrix[u][i])
            for i in range (u + 1 , d) :
                ans.append (matrix[i][r])
            if u != d :
                for i in range (r , l - 1 , - 1) :
                    ans.append (matrix[d][i])
            if l != r :
                for i in range (d - 1 , u , -1) :
                    ans.append (matrix[i][l])
            l += 1
            r -= 1
            u += 1
            d -= 1
        return ans