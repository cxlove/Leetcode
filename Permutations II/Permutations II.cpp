class Solution {
	public :
	vector <vector <int> > permuteUnique (vector <int> &num) {
		sort (num.begin () , num.end ());
		vector <vector <int> > ans;
		do {
			ans.push_back (num);
		}while (next_permutation (num.begin () , num.end()));
		ans.resize (unique (ans.begin () , ans.end ()) - ans.begin ());
		return ans;
	}
};
