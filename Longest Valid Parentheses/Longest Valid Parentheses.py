class Solution:
    # @param s, a string
    # @return an integer
    def longestValidParentheses(self, s):
        stack = []
        ans = 0
        for i in range (len (s)) :
            if s[i] == '(' : stack.append (i)
            else :
                if len (stack) == 0 or s[stack[-1]] != '(' :
                    stack.append (i)
                else :
                    stack.pop ()
                    if len (stack) == 0 : ans = i + 1
                    else : ans = (i - stack[-1]) if (i - stack[-1]) > ans else ans
        return ans