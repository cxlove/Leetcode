class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> s;
        for (int i = 0 ; i < (int)tokens.size () ; i ++) {
            if (tokens[i] == "+") {
                int A = s.top ();s.pop ();
                int B = s.top ();s.pop ();
                s.push (B + A);
            }
            else if (tokens[i] == "-") {
                int A = s.top ();s.pop ();
                int B = s.top ();s.pop ();
                s.push (B - A);
            }
            else if (tokens[i] == "*") {
                int A = s.top ();s.pop ();
                int B = s.top ();s.pop ();
                s.push (B * A);
            }
            else if (tokens[i] == "/") {
                int A = s.top ();s.pop ();
                int B = s.top ();s.pop ();
                s.push (B / A);
            }
            else {
                stringstream in;in << tokens[i];
                int A;in >> A;
                s.push (A);
            }
        }
        return s.top ();
    }
};