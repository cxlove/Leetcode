class Solution:
    # @return a boolean
    def isValid(self, s):
        stack = []
        for ch in s :
            if ch == ')' or ch == ']' or ch == '}' :
                if len (stack) == 0 : return False
                if ch == ')' and stack[-1] != '(' : return False
                if ch == ']' and stack[-1] != '[' : return False
                if ch == '}' and stack[-1] != '{' : return False
                stack.pop ()
            else : stack.append (ch)
        return True if len (stack) == 0 else False 