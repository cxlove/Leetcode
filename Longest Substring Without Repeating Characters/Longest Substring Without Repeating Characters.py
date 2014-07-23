class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        ans , l , j = 0 , len (s) , 0
        a = [0 for i in range (128)]
        for i in range (l) :
            while j < l :
                if a[ord (s[j])] == 1 : break
                a[ord (s[j])] += 1
                j += 1
            if (j - i) > ans : ans = j - i
            a[ord (s[i])] -= 1
        return ans
            