class Solution:
    # @param an integer
    # @return a list of string
    def dfs (self , prefix , left , right , s) :
        if prefix < 0 : return
        if not left and not right :
            self.ans.append (s)
        if left :
            self.dfs (prefix + 1 , left - 1 , right , s + '(')
        if right and prefix > 0 :
            self.dfs (prefix - 1 , left , right - 1 , s + ')')

    def generateParenthesis(self, n):
        self.ans = []
        self.dfs (0 , n , n , '')
        return self.ans