class Solution:
    # @return an integer
    def romanToInt(self, s):
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        numerals = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        ans = 0
        for i in range (len (values)) :
            l = len (numerals[i])
            while len (s) >= l and s[0 : l] == numerals[i] :
            	s = s[l :]
            	ans += values[i]
        return ans