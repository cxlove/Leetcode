vector <int> prime;
vector <bool> isPrime;
vector <int> minFact , minFactCnt , factCnt;
class Solution {
public:
    int bulbSwitch(int n) {
        if (!n) return 0;
        int ans = 1;
        while (ans * ans <= n) ans ++;
        return ans - 1;
        prime.clear ();
        isPrime.resize (n + 1 , true);
        minFact.resize (n + 1);minFactCnt.resize (n);factCnt.resize (n + 1);
        for (int i = 2 ; i <= n ; i ++) {
            if (isPrime[i]) {
                prime.push_back (i);
                minFact[i] = i;
                minFactCnt[i] = 1;
                factCnt[i] = 2;
            }
            for (auto p : prime) {
                if (i * p > n) break;
                isPrime[i * p] = false;
                minFact[i * p] = p;
                if (minFact[i] != p) {
                    minFactCnt[i * p] = 1;
                    factCnt[i * p] = factCnt[i] * 2;
                }
                else {
                    minFactCnt[i * p] = minFactCnt[i] + 1;
                    factCnt[i * p] = factCnt[i] / (minFactCnt[i] + 1) * (minFactCnt[i * p] + 1);
                }
                if (i % p == 0) break;
            }
            ans += factCnt[i] % 2;
        }
        return ans;
    }
};
