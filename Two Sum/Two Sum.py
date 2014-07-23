class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        mymap = dict ()
        ans = []
        for i in range (len (num)) :
            if mymap.has_key (target - num[i]) :
                ans.append (mymap.get (target - num[i]))
                ans.append (i + 1)
                return ans
            mymap[num[i]] = i + 1
        return ans