class Solution:
    # @return a list of lists of integer
    def generateMatrix(self, n):
        matrix = [[0 for i in range (n)] for j in range (n)]
        l = 0
        r = n - 1
        u = 0
        d = n - 1
        ans = []
        p = 1
        while l <= r and u <= d :
            for i in range (l , r + 1) :
                matrix[u][i] = p
                p += 1
            for i in range (u + 1 , d) :
                matrix[i][r] = p
                p += 1
            if u != d :
                for i in range (r , l - 1 , - 1) :
                    matrix[d][i] = p
                    p += 1
            if l != r :
                for i in range (d - 1 , u , -1) :
                    matrix[i][l] = p
                    p += 1
            l += 1
            r -= 1
            u += 1
            d -= 1
        return matrix