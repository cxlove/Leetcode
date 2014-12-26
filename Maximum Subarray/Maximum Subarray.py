class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxSubArray(self, A):
        ans = int (-1e60)
        mn , pre = 0 , 0
        for a in A :
            pre += a
            ans = max (ans , pre - mn)
            mn = min (mn , pre)
        return ans
