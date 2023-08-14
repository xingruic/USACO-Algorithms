#include<bits/stdc++.h>
using namespace std;
int n, m;
bool block[501][501];
struct sit {
    int i, j, f; // f = # of flips done
    bool g; // 0 = downward (+i), 1 = upward (-i)
    // leftward is -j, rightward is +j
    sit(int i = 0, int j = 0, bool g = 0, int f = 0) :i(i), j(j), g(g), f(f) {}
};
auto cmp = [](const sit &a, const sit &b) {
    if (a.j != b.j) return a.j < b.j;
    else if (a.i != b.i) return a.i < b.i;
    else return a.g < b.g;
    };
set < sit, decltype(cmp) > done(cmp);
queue<sit> q;
int ci, cj, di, dj;
int main() {
    memset(block, 0, sizeof(block));
    // memset(done, 0, sizeof(done));
    freopen("gravity.in", "r", stdin);
    freopen("gravity.out", "w", stdout);
    cin >> n >> m;
    char c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c;
            block[i][j] = c == '#';
            if (c == 'C') ci = i, cj = j;
            else if (c == 'D') di = i, dj = j;
        }
    }
    int i, minf = 0x7fffffff;
    for (i = ci; i <= n; i++) {
        if (block[i][cj]) break;
    }
    if (i <= n)
        q.push(sit(i - 1, cj, 0));
    sit t;
    while (!q.empty()) {
        t = q.front();
        q.pop();
        if (done.count(t)) continue;
        done.insert(t);
        if (t.j == dj) {
            if (t.g && t.i > di || t.g && t.i < di) {
                cout << di << ' ' << dj << ' ' << t.g << ' ' << t.f << endl;
                goto end;
            }
        }
        for (i = t.i; i <= n && i > 0; t.g ? i-- : i++) {
            if (block[i][t.j]) break;
        }
        if (i > n || i <= 0) {
            continue;
        }
        t.i = t.g ? i + 1 : i - 1;
        cout << t.i << ' ' << t.j << ' ' << t.g << ' ' << t.f << endl;
        if (t.i == di && t.j == dj) {
        end:
            minf = min(minf, t.f);
            cout << t.f << endl;
            continue;
        }
        if (t.j > 1 && !block[t.i][t.j - 1]) {
            q.push(sit(t.i, t.j - 1, t.g, t.f));
        }
        if (t.j < m && !block[t.i][t.j + 1]) {
            q.push(sit(t.i, t.j + 1, t.g, t.f));
        }
        q.push(sit(t.i, t.j, !t.g, t.f + 1));
    }
    if (minf == 0x7fffffff) cout << -1 << endl;
    else cout << minf << endl;
}