class Solution:
    # @return an integer
    def divide(self, dividend, divisor):
    	ans , sgn = 0 , 1
    	if (divisor < 0 and dividend > 0) or (divisor > 0 and dividend < 0) :
    		sgn = -1
    	if dividend < 0 : dividend = 0 - dividend
    	if divisor < 0 : divisor = 0 - divisor
    	for i in range (63 , -1 , -1) :
    		if dividend >= (divisor << i) :
    			ans |= 1 << i
    			dividend -= divisor << i
        return ans * sgn