#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<assert.h>
using namespace std;
const int maxn = 500;
char grid[maxn][maxn];
int n, m;
int ci, cj, di, dj;
bool vis[maxn][maxn][2] = { 0 };
int minc = 0x77777777;
int tc = -1;
int fall(int r, int c, bool down) {
    if (grid[r][c] == '#') return -1;
    int i;
    if (down) {
        for (i = r; i < n; i++) {
            if (i == di && c == dj) {
                minc = min(minc, tc + 1);
            }
            if (grid[i][c] == '#') break;
        }
        if (i == n) return -1;
        return i - 1;
    } else {
        for (i = r; i >= 0; i--) {
            if (i == di && c == dj) {
                minc = min(minc, tc + 1);
            }
            if (grid[i][c] == '#') break;
        }
        if (i == -1) return -1;
        return i + 1;
    }
}
struct step {
    step(int i, int j, int c, bool d) : i(i), j(j), c(c), d(d) {}
    int i, j, c;
    bool d;
};
int main() {
    freopen("gravity.in", "r", stdin);
    freopen("gravity.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < m; j++) {
            grid[i][j] = getchar();
            if (grid[i][j] == 'C') {
                ci = i, cj = j;
                grid[i][j] = '.';
            }
            if (grid[i][j] == 'D') {
                di = i, dj = j;
                grid[i][j] = '.';
            }
        }
    }
    // cout << fall(2, 1, 0) << endl;
    queue<step> q;
    q.push(step(fall(ci, cj, 1), cj, 0, 1));
    while (!q.empty()) {
        step t = q.front();
        q.pop();
        if (t.i == -1) continue;
        if (vis[t.i][t.j][t.d]) continue;
        vis[t.i][t.j][t.d] = 1;
        // cout << t.i << ' ' << t.j << endl;
        if (t.i == di && t.j == dj) {
            minc = min(minc, t.c);
            continue;
        }
        tc = t.c;
        q.push(step(fall(t.i, t.j, !t.d), t.j, t.c + 1, !t.d));
        if (t.j + 1 < n) q.push(step(fall(t.i, t.j + 1, t.d), t.j + 1, t.c, t.d));
        if (t.j > 0) q.push(step(fall(t.i, t.j - 1, t.d), t.j - 1, t.c, t.d));
        // cout << "\t(" << fall(t.i, t.j, !t.d) << ',' << t.j << ")\n";
        // cout << "\t(" << fall(t.i, t.j + 1, t.d) << ',' << t.j + 1 << ")\n";
        // cout << "\t(" << fall(t.i, t.j - 1, t.d) << ',' << t.j - 1 << ")\n";
    }
    if (minc == 0x77777777) cout << -1 << endl;
    else cout << minc << endl;
    return 0;
}