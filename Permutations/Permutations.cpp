class Solution {
public :
	vector <vector <int> > permute (vector <int> &num) {
		sort (num.begin () , num.end ());
		vector <vector <int> > ans;
		do {
			ans.push_back (num);
		}while (next_permutation (num.begin () , num.end()));
		return ans;
	}
};
