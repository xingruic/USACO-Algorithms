#include<iostream>
#include<cstring>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 4000;
int n, m;
set<int> edge[maxn + 1];
int order[maxn];
bool included[maxn + 1];
bool flooded[maxn + 1];
void dfs(int x) {
    if (flooded[x] || !included[x]) return;
    flooded[x] = 1;
    for (const int &i : edge[x]) {
        dfs(i);
    }
}
// @return whether or not the graph is connected after remove vertex x
// @param x the vertex to remove
string con_remove(int x = 0) {
    included[x] = 0;
    int i;
    for (i = 1; i < n; i++) if (included[i]) break;
    memset(flooded, 0, sizeof(flooded));
    dfs(i);
    for (i = 1; i <= n; i++) {
        if (included[i] && !flooded[i]) return "NO";
    }
    return "YES";
}
int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].insert(b);
        edge[b].insert(a);
    }
    for (int i = 0; i < n; i++) {
        cin >> order[i];
    }
    memset(included, 1, sizeof(included));
    cout << con_remove() << endl;
    for (int t = 0; t < n - 1; t++) {
        cout << con_remove(order[t]) << endl;
    }
}