#include <bits/stdc++.h>
using namespace std;
struct state {
    int cur, dist, numcon, cost;
    state(int cur, int dist = 0, int numcon = 0, int cost = 0) : cur(cur), dist(dist), numcon(numcon), cost(cost) {}
};
int n, m;
bool path[10001][10001];
int dist[10001];
int main() {
    freopen("conbarn.in", "r", stdin);
    freopen("conbarn.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        memset(path, 0, sizeof(path));
        memset(dist, 0x7f, sizeof(dist));
        cin >> n >> m;
        {
            int a, b;
            for (int i = 0; i < m; i++) {
                cin >> a >> b;
                path[a][b] = path[b][a] = 1;
            }
        }
        queue<state> q;
        q.push(state(1));
        state t(0);
        int ans = 0x7fffffff;
        while (!q.empty()) {
            t = q.front();
            q.pop();
            dist[t.cur] = t.dist;
            if (t.cur == n) {
                cout << t.cost << ' ' << t.numcon << endl;
                ans = min(ans, t.cost);
                continue;
            }
            for (int i = 1; i <= n; i++) {
                if (path[t.cur][i]) {
                    if (dist[i] <= t.dist)
                        continue;
                    q.push(state(i, t.dist + 1, t.numcon, t.cost));
                } else if (t.numcon < 2) {
                    q.push(state(i, t.dist + 1, t.numcon + 1, t.cost + (t.cur - i) * (t.cur - i)));
                }
            }
        }
        cout << ans << endl;
    }
}