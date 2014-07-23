class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map <int , int> mymap;
        vector <int> ans;
        for (int i = 0 ; i < numbers.size () ; i ++) {
            if (mymap.find (target - numbers[i]) != mymap.end ()) {
                ans.push_back (mymap[target - numbers[i]]);
                ans.push_back (i + 1);
                return ans;
            }
            mymap[numbers[i]] = i + 1;
        }
    }
};