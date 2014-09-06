class Solution:
    # @param A, a list of integers
    # @param target, an integer to be inserted
    # @return integer
    def searchInsert(self, A, target):
        if len (A) == 0 : return 0
        low , high , ans = 0 , len (A) - 1 , len (A)
        while low <= high :
            mid = (low + high) >> 1
            if A[mid] == target : return mid
            if A[mid] > target : ans , high = mid , mid - 1
            if A[mid] < target : low = mid + 1
        return ans