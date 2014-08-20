class Solution:
    # @return a list of lists of length 3, [[val1,val2,val3]]
    def threeSum(self, num):
    	num = sorted (num)
    	ans = []
    	n = len (num)
    	for i in range (0 , n) :
    		if i and num[i] == num[i - 1] : continue
    		k = n - 1 
    		for j in range (i + 1 , n) :
    			if j != i + 1 and num[j] == num[j - 1] : continue
    			while k > j :
    				if num[i] + num[j] + num[k] < 0 : break
    				if num[i] + num[j] + num[k] == 0 : 
    					ans.append ([num[i] , num[j] , num[k]])
    					break
    				k -= 1
    	return ans