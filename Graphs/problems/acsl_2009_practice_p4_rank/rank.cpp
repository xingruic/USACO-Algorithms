#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int n, k;
bool s[21][21];

bool visited[21], cycle[21];
int o;

void visit(int x) {
    if (visited[x]) {
        if (x == o) cycle[x] = 1;
        return;
    }
    visited[x] = 1;
    for (int i = 1; i <= n; i++) {
        if (s[x][i]) {
            visit(i);
        }
    }
}

int main() {
    // freopen64("rank.out", "w", stdout);
    cin >> n >> k;
    memset(s, 0, sizeof(s));
    {
        int a, b, i, j;
        while (k--) {
            cin >> a >> b >> i >> j;
            s[a][b] = !(s[b][a] = i < j);
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         if (s[i][j] == s[j][i]) cout << "- ";
    //         else cout << s[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    memset(cycle, 0, sizeof(cycle));
    for (o = 1; o <= n; o++) {
        if (cycle[o]) continue;
        memset(visited, 0, sizeof(visited));
        visit(o);
        // for (int j = 1; j <= n; j++) cout << visited[j] << ' ';cout << endl;
    }
    // cout << endl;
    // for (int i = 1; i <= n; i++) cout << cycle[i] << ' ';cout << endl;
    cout << count(cycle + 1, cycle + 1 + n, 1) << endl;
}