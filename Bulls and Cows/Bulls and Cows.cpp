class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0 , B = 0 , n = (int)secret.size ();
        vector <int> AA (10 , 0) , BB (10 , 0);
        for (int i = 0 ; i < n ; ++ i) {
            if (secret[i] == guess[i]) A ++;
            else {
                AA[secret[i] - '0'] ++;
                BB[guess[i] - '0'] ++;
            }
        }
        for (int i = 0 ; i < 10 ; i ++) {
            B += min (AA[i] , BB[i]);
        }
        char str[100];
        sprintf (str , "%dA%dB" , A , B);
        return string (str);
    }
};