
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = (int)words.size ();
        vector <vector <string> > line;
        int i = 0;
        while (i < n) {
            vector <string> eachLine;
            int length = words[i].length ();
            eachLine.push_back (words[i ++]);
            while (i < n && length + 1 + (int)words[i].length () <= maxWidth) {
                length += 1 + (int)words[i].length ();
                eachLine.push_back (words[i ++]);
            }
            line.push_back (eachLine);
        }
        vector <string> ans;
        for (int i = 0 ; i < (int)line.size () - 1 ; i ++) {
            string ret = "";
            int m = (int)line[i].size ();
            if (m == 1) {
                ret = line[i][0];
                for (int j = (int)line[i][0].length () ; j < maxWidth ; j ++) {
                    ret += " ";
                }
                ans.push_back (ret);
                continue;
            }
            int len = 0;
            for (int j = 0 ; j < m ; j ++) {
                len += (int)line[i][j].length ();
            }
            ret = line[i][0];
            int d = (maxWidth - len) / (m - 1);
            for (int j = 0 ; j < (maxWidth - len) % (m - 1) ; j ++) {
                for (int k = 0 ; k < d + 1 ; k ++) ret += " ";
                ret += line[i][j + 1];
            }
            for (int j = (maxWidth - len) % (m - 1) ; j < m - 1 ; j ++) {
                for (int k = 0 ; k < d ; k ++) ret += " ";
                ret += line[i][j + 1];
            }
            ans.push_back (ret);
        }
        vector <string> lastLine = line[(int)line.size () - 1];
        string ret = lastLine[0];
        for (int j = 1 ; j < (int)lastLine.size () ; j ++) {
            ret += " " + lastLine[j];
        }
        while ((int)ret.size () < maxWidth) ret += " ";
        ans.push_back (ret);
        return ans;
    }
};