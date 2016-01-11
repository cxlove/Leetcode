class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = (int)words.size ();
        int bit[n] , ans = 0;
        for (int i = 0 ; i < n ; i ++) {
            bit[i] = 0;
            for (auto ch : words[i]) {
                bit[i] |= 1 << (ch - 'a');
            }
            for (int j = 0 ; j < i ; j ++) {
                if (!(bit[i] & bit[j])) {
                    ans = max (ans , (int)words[i].size () * (int)words[j].size ());
                }
            }
        }
        return ans;
    }
};
