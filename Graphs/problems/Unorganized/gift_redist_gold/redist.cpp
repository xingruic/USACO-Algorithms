#include <bits/stdc++.h>
using namespace std;
int n;
int pref[19][19];
bool path[19][19];
bool hols[19];
void dfs(int x, int y) {
    if (path[x][y])
        return;
    path[x][y] = 1;
    for (int i = 1; i <= n; i++) {
        if (pref[y][i] == y)
            break;
        // cout << y << ' ' << i << ' ' << pref[y][i] << ' ' << hols[y] << ' ' << hols[pref[y][i]] << endl;
        if (hols[pref[y][i]] != hols[y]) {
            continue;
        }
        dfs(x, pref[y][i]);
    }
    return;
}
int main() {
    freopen("redist.in", "r", stdin);
    freopen("redist.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> pref[i][j];
        }
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        memset(path, 0, sizeof(path));
        string breeds;
        cin >> breeds;
        for (int i = 1; i <= n; i++) {
            hols[i] = (breeds[i - 1] == 'H');
        }
        for (int i = 1; i <= n; i++) {
            dfs(i, i);
        }
        cout << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << path[i][j] << ' ';
            }
            cout << endl;
        }
    }
}