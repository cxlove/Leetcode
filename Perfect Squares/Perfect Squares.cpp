class Solution {
public:
    int bfs (int n) {
        vector <int> dist (n + 1 , -1);
        queue <int> que;
        que.push (0);dist[0] = 0;
        while (!que.empty ()) {
            int u = que.front ();que.pop ();
            if (u == n) return dist[u];
            for (int i = 1 ; u + i * i <= n ; i ++) {
                if (dist[u + i * i] == -1) {
                    dist[u + i * i] = dist[u] + 1;
                    que.push (u + i * i);
                }
            }
        }
    }
    int numSquares(int n) {
        return bfs (n);
    }
};
