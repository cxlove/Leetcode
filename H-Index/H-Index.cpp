class Solution {
public:
    int hIndex(vector<int>& cit) {
        int n = (int)cit.size ();
        sort (cit.rbegin () , cit.rend ());
        for (int i = n , j = 0 ; i >= 0 ; i --) {
            while (j < n && cit[j] > i) j ++;
            int k = j;
            while (k < n && cit[k] == i) k ++;
            if (j <= i && k >= i) return i;
            j = k;
        }
        return 0;
    }
};
