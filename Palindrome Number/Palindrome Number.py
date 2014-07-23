class Solution:
    # @return a boolean
    def isPalindrome(self, x):
        if x < 0 : return False
        x = str (x)
        l = len (x)
        for i in range (l) :
            if x[i] != x[l - 1 - i] :
                return False;
        return True