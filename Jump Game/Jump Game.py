class Solution:
    # @param A, a list of integers
    # @return a boolean
    def canJump(self, A):
        n = len (A)
        mx , now = 0 , 0
        while now <= mx and now < n :
            mx = max (mx , now + A[now])
            now += 1
        return True if mx >= n - 1 else False