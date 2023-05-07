#include <bits/stdc++.h>
using namespace std;
int n;
int pref[501][501];
bool path[501][501];
void dfs(int x, int y) {
    if (path[x][y])
        return;
    path[x][y] = 1;
    for (int i = 1; i <= n; i++) {
        if (pref[y][i] == y)
            break;
        dfs(x, pref[y][i]);
    }
    return;
}
int main() {
    memset(path, 0, sizeof(path));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> pref[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        dfs(i, i);
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << path[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (path[pref[i][j]][i]) {
                cout << pref[i][j] << endl;
                break;
            }
        }
    }
}