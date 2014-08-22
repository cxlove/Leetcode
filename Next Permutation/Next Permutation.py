class Solution:
    # @param num, a list of integer
    # @return a list of integer
    def nextPermutation(self, num):
        n = len (num)
        for i in range (n - 1 , -1 , -1) :
            for j in range (n - 1 , i , -1) :
                if num[j] > num[i] :
                    a = num[0 : i] + num[j : j + 1] + sorted (num[i : j] + num[j + 1 : n])
                    return a
        return sorted (num)