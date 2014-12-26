class Solution:
    # @param s, a string
    # @return an integer
    def lengthOfLastWord(self, s):
        s = s.strip ()
        n = len (s)
        ans = 0
        for i in range (n - 1 , -1 , -1) :
            if s[i] == ' ' :
                break
            ans += 1
        return ans