#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 4e4 + 1;
int b, e, p, n, m;
int bd[MAXN], ed[MAXN], nd[MAXN]; // distance from field i to field 1, 2, and n respectively.
vector<int> adj[MAXN];
void compute_dists(int d[], int step, int start) {
    memset(d, -1, sizeof(int) * MAXN);
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    while (!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        if (d[t.first] != -1) continue;
        d[t.first] = t.second;
        t.second += step;
        for (int &x : adj[t.first]) {
            q.push(make_pair(x, t.second));
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << d[i] << ' ';
    // }cout << endl;
}
int main() {
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);
    cin >> b >> e >> p >> n >> m;
    {
        int x, y;
        for (int i = 1; i <= m; i++) {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }
    compute_dists(bd, b, 1);
    compute_dists(ed, e, 2);
    compute_dists(nd, p, n);
    int min_energy = nd[1] + nd[2];
    for (int i = 1; i <= n; i++) {
        if (bd[i] + ed[i] + nd[i] < min_energy) {
            min_energy = bd[i] + ed[i] + nd[i];
        }
    }
    cout << min_energy << endl;
}