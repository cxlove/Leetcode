class Solution:
    # @return an integer
    def atoi(self, str):
        ans , sig = 0 , 0
        str = str.strip ()
        for ch in str :
            if ch == '-' : 
                if sig : break
                else : sig = -1
            elif ch == '+' : 
                if sig : break
                else : sig = 1
            else: 
                if ch < '0' or ch > '9' : break
                else : ans = ans * 10 + int (ch)
        if sig == 0 : sig = 1
        ans = ans * sig
        if ans < -2147483648 : return -2147483648
        if ans > 2147483647 : return 2147483647
        return ans