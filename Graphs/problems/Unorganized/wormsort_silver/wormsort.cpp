#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
// #include<assert.h>
#include<map>
using namespace std;
int n, M, p[100001];
map<int, int> edge[100001];
int flooded[100001];
void flood(int x, int m, int id) {
    if (flooded[x]) return;
    flooded[x] = id;
    for (pair<int, int> j : edge[x]) {
        if (j.second >= m)
            flood(j.first, m, id);
    }
}
void binsearch(int l = 1, int r = 2000000000) { // binary search the minimum width
    if (l == r) {
        cout << l << endl;
        return;
    }
    int m = (l + r) / 2 + 1;
    memset(flooded, 0, sizeof(flooded));
    for (int i = 1; i <= n; i++) {
        if (!flooded[i] && p[i] != i) {
            flood(i, m, i);
        }
    }
    // cout << l << ' ' << r << ' ' << m << endl;
    // for (int i = 1; i <= n; i++) cout << flooded[i] << ' ';
    // cout << endl;
    for (int i = 1; i <= n; i++) {
        if (p[i] != i) {
            if (flooded[p[i]] != flooded[i]) {
                binsearch(l, m - 1);
                return;
            }
        }
    }
    binsearch(m, r);
}
int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    cin >> n >> M;
    {
        int a, b, c;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        for (int i = 1; i <= M; i++) {
            cin >> a >> b >> c;
            edge[a].emplace(b, c);
            edge[b].emplace(a, c);
        }
    }
    int i;
    for (i = 1; i <= n; i++) {
        if (p[i] != i) {
            break;
        }
    }
    if (i > n) cout << -1 << endl;
    else binsearch();
}