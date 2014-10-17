#-*-coding:utf-8 -*-
class Solution:
    # @param A, a list of integers
    # @return an integer
    def trap(self, A):
    	n = len (A)
    	if n < 3 : return 0
    	preMax = [0] * n
    	preMax[0] = A[0]
    	for i in range (1 , n) :
    		preMax[i] = max (preMax[i - 1] , A[i])
    	sufMax = [0] * n
    	sufMax[n - 1] = A[n - 1]
    	for i in range (n - 2 , -1 , -1) :
    		sufMax[i] = max (sufMax[i + 1] , A[i])
    	ans = 0
    	for i in range (1 , n - 1) :
    		ans = ans + min (preMax[i] , sufMax[i]) - A[i]
    	return ans
