#-*-coding:utf-8 -*-
class Solution:
    # @param num1, a string
    # @param num2, a string
    # @return a string
    def multiply(self, s, e):
        n , m = len (s) , len (e)
        ans = [0] * (n + m)
        for i in range (n) :
        	for j in range (m) :
        		ans[i + j] += (ord (s[n - 1 - i]) - ord ('0')) * (ord (e[m - 1 - j]) - ord ('0'))
        for i in range (n + m - 1) :
        	ans[i + 1] += ans[i] / 10
        	ans[i] %= 10
        ret = ''
        zero = 1
        for i in range (n + m - 1 , -1 , -1) :
        	if ans[i] == 0 :
        		if zero : continue
        	zero = 0
        	ret += str (ans[i])
        if ret == '' : ret = '0'
        return ret 