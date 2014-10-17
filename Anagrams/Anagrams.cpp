class Solution {
	public :
	vector <string> anagrams (vector <string> &s) {
		vector <string> t = s;
		vector <string> ans;
		map <string , int> mymap;
		for (int i = 0 ; i < (int)s.size () ; i ++) {
			sort (s[i].begin () , s[i].end());
			if (mymap.find (s[i]) == mymap.end())
				mymap[s[i]] = i;
			else {
				if (mymap[s[i]] >= 0) {
					ans.push_back (t[mymap[s[i]]]);
					mymap[s[i]] = -1;
				}
				ans.push_back (t[i]);
			}
		}
		return ans;
	}
};
