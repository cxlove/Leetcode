class Solution:
	# @param A, a list of integers	    
	# @return an integer
	def jump(self, A): 
		n = len (A)
		if n == 1 : return 0
		now , next , ans = 0 , 0 , 0
		while now < n - 1 :
			pos = next + 1
			ans += 1
			while now <= next :
				pos = max (pos , A[now] + now)
				now += 1
				if pos >= n - 1 :
					return ans
			next = pos
		return ans
		
