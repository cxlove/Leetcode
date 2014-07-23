class Solution {
public:
    int gao (int a[] , int n , int b[] , int m , int k) {
        int low = 0 , high = n , mid;
        if (n == 0) return b[k - 1];
        if (m == 0) return a[k - 1];
        while (low <= high) {
            mid = (low + high) >> 1;
            int p = mid , q = (k - p);
            if (q < 0) {
                high = mid - 1;
            }
            else if (q > m) {
                low = mid + 1;
            }
            else {
                 if (p == 0) {
                     if (b[q - 1] <= a[0]) return b[q - 1];
                     else low = mid + 1;
                 }
                 else if (q == 0) {
                     if (a[p - 1] <= b[0]) return a[p - 1];
                     else high = mid - 1;
                 }
                 else if (p == n && q == m) {
                    return max (a[p - 1] , b[q - 1]);
                 }
                 else if (p == n) {
                     if (a[p - 1] <= b[q]) return max (a[p - 1] , b[q - 1]);
                     else high = mid - 1;
                 }
                 else if (q == m) {
                     if (b[q - 1] <= a[p]) return max (a[p - 1] , b[q - 1]);
                     else low = mid + 1;
                 }
                 else {
                     if (a[p - 1] <= b[q] && b[q - 1] <= a[p]) return max (a[p - 1] , b[q - 1]);
                     else if (a[p - 1] > b[q]) high = mid - 1;
                     else low = mid + 1;
                 }
            }
        }
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m + n) & 1) return gao (A , m , B , n , (m + n + 1) / 2);
        else return (gao (A , m , B , n , (m + n) / 2) + gao (A , m , B , n , (m + n) / 2 + 1)) / 2.0;
    }
};