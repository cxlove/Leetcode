class Solution :
	def rotate (self , matrix) :
		n = len (matrix)
		ans = [[0 for j in range (n)] for i in range (n)]
		for i in range (n) :
			for j in range (n) :
				ans[j][n - i -  1] = matrix[i][j]
		return ans
