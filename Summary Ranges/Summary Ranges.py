class Solution:
    # @param {integer[]} nums
    # @return {string[]}
    def summaryRanges(self, nums):
        if len (nums) == 0 : return []
        l , r = nums[0] , nums[0]
        ans = []
        for i in xrange (1 , len (nums)) :
            if nums[i] == r + 1 :
                r += 1
            else :
                if l == r : ans.append (str (l))
                else : ans.append (str (l) + '->' + str (r))
                l = r = nums[i]
        if l == r : ans.append (str (l))
        else : ans.append (str (l) + '->' + str (r))
        return ans
