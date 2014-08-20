
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort (num.begin () , num.end ());
        set <vector <int> > ans;
        int n = num.size ();
        for (int i = 0 ; i < n ; i ++) {
            for (int j = i + 1 ; j < n ; j ++) {
                int l = j + 1 , r = n - 1;
                while (l < r) {
                    int s = num[i] + num[j] + num[l] + num[r];
                    if (s == target) {
                        vector <int> t;
                        t.push_back (num[i]);
                        t.push_back (num[j]);
                        t.push_back (num[l]);
                        t.push_back (num[r]);
                        ans.insert (t);
                        l ++;
                    }
                    else if (s < target) l ++;
                    else r --;
                }
            }
        }
        vector <vector <int> > ret;
        for (set <vector <int> > :: iterator it = ans.begin () ; it != ans.end () ; it ++) {
            ret.push_back (*it);
        }
        return ret;
    }
};