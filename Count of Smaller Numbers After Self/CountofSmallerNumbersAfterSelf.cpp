class BIT {
    public:
    BIT () {}
    BIT (int _n):n(_n) {s.resize (n + 1 , 0);}
    inline void add (int x) {
        for (int i = x ; i <= n ; i += i & -i) {
            s[i] ++;
        }
    }
    inline int sum (int x) {
        int ret = 0;
        for (int i = x ; i > 0 ; i -= i & -i) {
            ret += s[i];
        }
        return ret;
    }
    private:
    vector <int> s;
    int n;
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector <int> a (nums);
        sort (a.begin () , a.end ());
        a.resize (unique (a.begin () , a.end ()) - a.begin ());
        int n = (int)a.size () , m = (int)nums.size ();
        for (int i = 0 ; i < m ; i ++) {
            nums[i] = lower_bound (a.begin () , a.end () , nums[i]) - a.begin () + 1;
        }
        BIT bit (n);
        vector <int> ans (m , 0);
        for (int i = m - 1 ; i >= 0 ; i --) {
            ans[i] = bit.sum (nums[i] - 1);
            bit.add (nums[i]);
        }
        return ans;
    }
};
