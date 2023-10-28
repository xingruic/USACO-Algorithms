#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1000;
int n, m, c;
int earn[maxn + 1];
bool adj[maxn + 1][maxn + 1];
int main() {
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) {
        cin >> earn[i];
    }
    memset(adj, 0, sizeof(adj));
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
    }
}