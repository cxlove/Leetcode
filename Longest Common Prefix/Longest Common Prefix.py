class Solution:
    # @return a string
    def longestCommonPrefix(self, strs):
        if len (strs) == 0 : return ''
        ans = strs[0]
        for s in strs :
        	i = 0
        	while i < len (ans) :
        		if i >= len (s) or s[i] != ans[i] :
        			ans = ans[0 : i]
        			break
        		i += 1
        return ans