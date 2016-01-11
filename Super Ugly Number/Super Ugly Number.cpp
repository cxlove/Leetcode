class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = (int)primes.size ();
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
