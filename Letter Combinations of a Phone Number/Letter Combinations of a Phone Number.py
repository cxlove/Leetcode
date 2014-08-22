class Solution:
    # @return a list of strings, [s1, s2]
    def letterCombinations(self, digits):
        word = [' ' , '' , 'abc' , 'def' , 'ghi' , 'jkl' , 'mno' , 'pqrs' , 'tuv' , 'wxyz']
        ans = ['']
        for ch in digits :
            id = ord (ch) - ord ('0')
            t  = ans[:]
            del ans[:]
            for s in t :
                for c in word[id] :
                    ans.append (s + c)
        return ans