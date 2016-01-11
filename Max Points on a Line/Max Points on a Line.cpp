/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int ans = 0;
        for (int i = 0 ; i < points.size () ; i ++) {
            map <pair <int , int> , int> s;
            int ret = 0 , most = 0;
            for (int j = 0 ; j < points.size () ; j ++) {
                int A = points[i] .x - points[j].x , B = points[i].y - points[j].y;
                if (!A && !B) ret ++;
                else {
                    int g = __gcd (A , B);
                    A /= g; B /= g;
                    if (A < 0) A *= -1 , B *= -1;
                    s[make_pair (A , B)] ++;
                    most = max (most , s[make_pair (A , B)]);
                } 
            }
            ans = max (ans , ret + most);
        }
        return ans;
    }
};