class Solution:
    # @return a string
    def convert(self, s, nRows):
        if nRows == 1 : return s
        ans , l = "" , len (s)
        for i in range (nRows) :
            j , k = i , 1
            A = (nRows - 1 - i) * 2
            B = i * 2
            if i == 0 or i == nRows - 1 : A = B = max (A , B)
            while j < l :
                ans += s[j]
                j += A if k else B
                k = 1 - k
        return ans