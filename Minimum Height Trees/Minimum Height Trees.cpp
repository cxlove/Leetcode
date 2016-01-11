class Solution {
public:
    void dpDown (int u , int pre , vector <vector<int> > &e , vector<int> &down) {
        down[u] = 1;
        for (int i = 0 ; i < (int)e[u].size () ; i ++) {
            int v = e[u][i];
            if (v != pre) {
                dpDown (v , u , e , down);
                down[u] = max (down[u] , down[v] + 1);
            }
        }
    }
    
    void dpUp (int u , int pre , vector <vector <int> > &e , vector <int> &down , vector <int> &up) {
        int first = -1 , second = -1;
        for (int i = 0 ; i < (int)e[u].size () ; i ++) {
            int v = e[u][i];
            if (v != pre) {
                if (down[v] > first) {
                    second = first;
                    first = down[v];
                }
                else if (down[v] >= second) {
                    second = down[v];
                }
            }
        }
        
        for (int i = 0 ; i < (int)e[u].size () ; i ++) {
            int v = e[u][i];
            if (v != pre) {
                int upMax = up[u];
                if (down[v] == first) upMax = max (upMax , second + 1);
                else upMax = max (upMax , first + 1);
                up[v] = upMax + 1;
                dpUp (v , u , e , down , up);
            }
        }
    }
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector <vector <int> > e (n);
        vector <int> down (n , 1);
        vector <int> up (n , 1);
        for (int i = 0 ; i < n - 1 ; i ++) {
            e[edges[i].first].push_back (edges[i].second);
            e[edges[i].second].push_back (edges[i].first);
        }
        
        dpDown (0 , -1 , e , down);
        dpUp (0 , -1 , e , down , up);
        int minDepth = n;
        for (int i = 0 ; i < n ; i ++) {
            minDepth = min (minDepth , max (up[i] , down[i]));
        }

        vector <int> ans;
        for (int i = 0 ; i < n ; i ++) {
            if (max (up[i] , down[i]) == minDepth) {
                ans.push_back (i);
            }
        }

        return ans;
    }
};