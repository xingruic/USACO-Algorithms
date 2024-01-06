#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
const int maxn = 1e5;
int n, m;
bool g[maxn + 1];
struct Fr {
    int a, b;
    bool g;
}fr[maxn + 1];
vector<int> adj[maxn + 1];
int comp[maxn + 1]; // component #
void dfs(int x) {
    for (int i : adj[x]) {
        if (!comp[i] && g[i] == g[x]) {
            comp[i] = comp[x];
            dfs(i);
        }
    }
}
int ncomps = 0;
int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    cin >> n >> m;
    getchar();
    for (int i = 1; i <= n; i++) {
        g[i] = getchar() == 'G';
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= m; i++) {
        char c;
        cin >> fr[i].a >> fr[i].b >> c;
        fr[i].g = c == 'G';
    }
    memset(comp, 0, sizeof(comp));
    for (int i = 1; i <= n; i++) {
        if (!comp[i]) {
            comp[i] = ++ncomps;
            dfs(i);
        }
    }
    for (int i = 1; i <= m; i++) {
        // cout << endl << con << ' ';
        if (comp[fr[i].a] != comp[fr[i].b]) {
            cout << 1;
        } else {
            cout << (fr[i].g == g[fr[i].a]);
        }
    }
    cout << endl;
}