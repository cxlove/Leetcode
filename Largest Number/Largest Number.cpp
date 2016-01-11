class Solution {
public:
    static bool cmp (const string &a , const string &b) {
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector <string> s;
        for (int i = 0 ; i < (int)nums.size () ; i ++) {
            char ch[10];
            sprintf (ch , "%d" , nums[i]);
            s.push_back (string (ch));
        }
        sort (s.begin () , s.end () , cmp);
        if (s[0] == "0") return "0";
        string ans = "";
        for (int i = 0 ; i < (int)s.size () ; i ++) {
            ans += s[i];
        }
        return ans;
    }
};