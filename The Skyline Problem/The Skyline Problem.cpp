struct Tree {
    int left , right , mx , lazy;
};
vector <Tree> L;
vector <int> height;
#define lson step << 1
#define rson step << 1 | 1
void build (int step , int l , int r) {
    L[step].left = l;
    L[step].right = r;
    L[step].mx = L[step].lazy = 0;
    if (l == r) return ;
    int m = l + r >> 1;
    build (lson , l , m);
    build (rson , m + 1 , r);
}
void update (int step , int l , int r , int v);
void push_down (int step) {
    int l = L[step].left , r = L[step].right , m = l + r >> 1;
    int &z = L[step].lazy;
    if (z) {
        update (lson , l , m , z);
        update (rson , m + 1 , r , z);
        z = 0;
    }
}
void update (int step , int l , int r , int v) {
    if (L[step].left == l && L[step].right == r) {
        L[step].mx = max (L[step].mx , v);
        L[step].lazy = max (L[step].lazy , v);
        return ;
    }
    push_down (step);
    int m = L[step].left + L[step].right >> 1;
    if (r <= m) update (lson , l , r , v);
    else if (l > m) update (rson , l , r , v);
    else {
        update (lson , l , m , v);
        update (rson , m + 1 , r , v);
    }
    L[step].mx = max (L[lson].mx , L[rson].mx);
}
int query (int step , int p) {
    if (L[step].left == L[step].right) {
        return L[step].mx;
    }
    push_down (step);
    int m = L[step].left + L[step].right >> 1;
    if (p <= m) return query (lson , p);
    else return query (rson , p);
}
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        buildings.push_back (vector <int> {0 , INT_MAX , 0});
        int n = buildings.size ();
        vector <int> x;
        for (int i = 0 ; i < n ; i ++) {
            x.push_back (buildings[i][0]);
            x.push_back (buildings[i][1]);
        }
        
        sort (x.begin () , x.end ());
        x.resize (unique (x.begin () , x.end ()) - x.begin ());
        int m = x.size ();
        L.resize (m << 2);
        build (1 , 1 , m);
        
        for (int i = 0 ; i < n ; i ++) {
            int l = lower_bound (x.begin () , x.end () , buildings[i][0]) - x.begin () + 1;
            int r = lower_bound (x.begin () , x.end () , buildings[i][1]) - x.begin () + 1;
            update (1 , l , r - 1 , buildings[i][2]);
        }
        
        height.resize (m);
        height[0] = 0;
        for (int i = 1 ; i < m ; i ++) {
            height[i] = query (1 , i);
        }
        
        vector <pair <int , int> > ans;
        for (int i = 1 ; i < m ; i ++) {
            if (height[i] != height[i - 1]) {
                ans.push_back (make_pair (x[i - 1] , height[i]));
            }
        }
        if (height[m - 1] != 0) ans.push_back (make_pair (INT_MAX , 0));
        return ans;
    }
};
