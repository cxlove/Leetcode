vis = [[-1 for x in range (100)] for i in range (100)]
class Solution:
    # @return a boolean
    def isMatch(self, s, p):
        ls , lp = len (s) , len (p)
        if lp > 0 and ls == 0 : return False
        if lp == 0 and ls == 0 : return True
        if lp == 0 and ls > 0 :
            if s[0] == '.' : return False
            if ls > 1 and s[1] == '*' : return self.isMatch (s , p[2 : ])
            return False
        if lp == 1 or (lp > 1 and p[1] != '*') :
            if s[0] == p[0] or p[0] == '.' : return self.isMatch (s[1 : ] , p[1 : ])
            return False
        cnt = 0
        if vis[ls][lp] != -1 : return True if vis[ls][lp] else False
        if self.isMatch (s , p[2 : ]) : 
            vis[ls][lp] = 1
            return True
        while cnt < ls and (s[cnt] == p[0] or p[0] == '.') :
            if self.isMatch (s[cnt + 1 : ] , p[2 : ]) : 
                vis[ls][lp] = 1
                return True
            cnt += 1
        vis[ls][lp] = 0
        return False