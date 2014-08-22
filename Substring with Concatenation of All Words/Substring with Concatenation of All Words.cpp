class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        if (L.size () == 0) return vector <int> ();
        map <string , int> dataSet;
        int n = L.size () , m = L[0].size ();
        for (int i = 0 ; i < n ; i ++) {
            dataSet[L[i]] ++;
        }
        vector <int> ans;
        for (int i = 0 ; i <= (int)S.size () - n * m ; i ++) {
            map <string , int> p = dataSet;
            int ok = 1;
            for (int j = 0 ; j < n ; j ++) {
                string t = S.substr (i + j * m , m);
                if (p.find (t) == p.end ()) {
                    ok = 0;
                    break;
                }
                if (p[t] -- == 0) {
                    ok = 0;
                    break;
                }
            }
            if (ok) ans.push_back (i);
        }
        return ans;
    }
};