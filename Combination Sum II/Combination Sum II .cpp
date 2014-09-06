class Solution {
public:
    vector <vector <int> > ans;
    void dfs (vector <int> &a , int idx , int remain , vector <int> use) {
        if (remain == 0) {
            ans.push_back (use);
            return ;
        }
        if (idx == a.size ()) return;
        if (a[idx] > remain) return ;
        int t = idx + 1;
        while (t < a.size () && a[t] == a[idx]) t ++;
        dfs (a , t , remain , use);
        remain -= a[idx];
        use.push_back (a[idx]);
        dfs (a , idx + 1 , remain , use);
    }
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort (candidates.begin () , candidates.end ());
        dfs (candidates , 0 , target , vector <int> (0));
        return ans;
    }
};