class Solution:
    # @return a string
    def getPermutation(self, n, k):
        a = [i + 1 for i in range (n)]
        fac = lambda p : 1 if p <= 1 else p * fac (p - 1)
        ans = []
        for i in range (n) :
            haha = fac (n - i - 1)
            for j in range (n - i) :
                if haha >= k :
                    ans.append (a[j])
                    del a[j]
                    break
                k -= haha
        return ''.join (str (p) for p in ans)