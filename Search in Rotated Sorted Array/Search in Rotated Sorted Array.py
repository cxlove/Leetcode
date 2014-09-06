class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return an integer
    def search(self, A, target):
        n = len (A)
        if n == 0 : return -1
        low , high  = 0 , n - 1
        while low <= high :
            mid = (low + high) >> 1
            if A[mid] == target : return mid 
            if A[mid] >= A[0] :
                if target < A[0] : low = mid + 1
                else :
                    if A[mid] >= target : high = mid - 1;
                    else : low = mid + 1
            if A[mid] <= A[-1] :
                if target > A[-1] : high = mid - 1
                else :
                    if A[mid] >= target : high = mid - 1
                    else : low = mid + 1;
        return -1