class Solution {
    public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int low = 1 , high = min ((int)1e6 , x) , mid , ans;
        while (low <= high) {
            mid = low + ((high - low) >> 1);
            if (x / mid >= mid) {                    
                ans = mid;
                low = mid + 1;                          
            }
            else high = mid - 1;         
        }
        return ans;    
    }
};
