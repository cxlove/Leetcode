class Solution:
    # @return an integer
    def abs (d) :
    	return d if d > 0 else -d

    def threeSumClosest(self, num, target):
    	num = sorted (num)
    	ans = int (1e18)
    	n = len (num)
    	for i in range (0 , n) :
    		j , k = i + 1 , n - 1
    		while j < k :
    			s = num[i] + num[j] + num[k]
    			if abs (s - target) < abs (ans - target) : ans = s
    			if s < target : j += 1
    			else : k -= 1 
    	return ans