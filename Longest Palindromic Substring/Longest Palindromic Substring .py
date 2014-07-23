# Manacher
class Solution:
    # @return a string
    def longestPalindrome(self, s):
        n = len (s)
        e = ['@']
        for ch in s : e.append (ch) , e.append ('#')
        e.append ('%')
        p = [1 for i in range (2 * n + 1)]
        maxId , id , ret , pos = 1 , 0 , 0 , 0
        for i in range (1 , 2 * n + 1) :
            if maxId > i :
                p[i] = min (maxId - i , p[id - (i - id)])
            while e[i - p[i]] == e[i + p[i]] : p[i] += 1
            if i + p[i] > maxId : maxId , id = i + p[i] , i
            if p[i] > ret :  ret , pos = p[i] , i
        ans = ""
        for i in range (pos - p[pos] + 1 , pos + p[pos]) :
            if e[i] != '%' and e[i] != '@' and e[i] != '#' :
                ans += (e[i])
        return ans