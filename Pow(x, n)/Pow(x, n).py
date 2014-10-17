class Solution :
	def binPow (self , a , b) :
		ret = 1.0
		while b > 0 :
			if b % 2 == 1 : ret = ret * a
			a = a * a
			b >>= 1
		return ret

	def pow (self , a , b) :
		if b < 0 : return 1.0 / self.binPow (a , -b)
		return self.binPow (a , b)
