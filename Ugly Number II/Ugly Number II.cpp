class Solution {
public:
    int nthUglyNumber(int n) {
        int m = 3 , primes[3] = {2 , 3 , 5};
        vector <int> cnt (m , 0);
        vector <int> ugly (n , INT_MAX);
        ugly[0] = 1;
        for (int i = 1 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                ugly[i] = min (ugly[i] , ugly[cnt[j]] * primes[j]);
            }
            for (int j = 0 ; j < m ; j ++) {
                cnt[j] += ugly[i] == ugly[cnt[j]] * primes[j];
            }
        }
        return ugly[n - 1];
    }
};
