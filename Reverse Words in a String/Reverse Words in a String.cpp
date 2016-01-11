class Solution {
public:
    void reverseWords(string &s) {
        string ans = "";
        stringstream  in;
        in << s;
        string t;
        while (in >> t) {
            reverse (t.begin () , t.end ());
            if (ans != "") ans += " ";
            ans += t; 
        }
        s = ans;
        reverse (s.begin () , s.end ());
    }
};