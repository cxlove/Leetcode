class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return a list of length 2, [index1, index2]
    def searchRange(self, A, target):
        if len (A) == 0 : return [-1 , -1]
        low , high , l = 0 , len (A) - 1 , -1
        while low <= high :
            mid = (low + high) >> 1
            if A[mid] == target : l , high = mid , mid - 1
            elif A[mid] > target : high = mid - 1
            else : low = mid + 1
        low , high , r = 0 , len (A) - 1 , -1
        while low <= high :
            mid = (low + high) >> 1
            if A[mid] == target : r , low = mid , mid + 1
            elif  A[mid] > target : high = mid - 1
            else : low = mid + 1
        return [l , r]