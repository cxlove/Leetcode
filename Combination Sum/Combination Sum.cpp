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
        dfs (a , idx + 1 , remain , use);
        while (remain >= a[idx]) {
            remain -= a[idx];
            use.push_back (a[idx]);
            dfs (a , idx + 1 , remain , use);
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort (candidates.begin () , candidates.end ());
        dfs (candidates , 0 , target , vector <int> (0));
        return ans;
    }
};