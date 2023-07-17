#include <bits/stdc++.h>
using namespace std;
int g[501][501];
int ps100[501][501]; // prefix sum of number of 100s
int l100[501][501]; // prefix sum of number of patches with g<100
int n;
int main() {
    memset(g, -1, sizeof(g));
    memset(ps100, 0, sizeof(ps100));
    memset(l100, 0, sizeof(l100));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
            ps100[i][j] = ps100[i - 1][j] + ps100[i][j - 1] - ps100[i - 1][j - 1] + (g[i][j] == 100);
            l100[i][j] = l100[i - 1][j] + l100[i][j - 1] - l100[i - 1][j - 1] + (g[i][j] < 100);
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++)
    //         cout << ps100[i][j] << ' ';
    //     cout << endl;
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++)
    //         cout << l100[i][j] << ' ';
    //     cout << endl;
    // }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (ps100[n][n] - ps100[i - 1][n] == 0)
            continue;
        for (int j = 1; j <= n; j++) {
            if (g[i][j] < 100)
                continue;
            if (ps100[n][n] - ps100[n][j - 1] - ps100[i - 1][n] + ps100[i - 1][j - 1] == 0)
                continue;
            for (int k = i; k <= n; k++) {
                if (ps100[k][n] - ps100[i - 1][n] == 0)
                    continue;
                for (int l = j; l <= n; l++) {
                    // cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << l100[k][l] - l100[k][j - 1] - l100[i - 1][l] + l100[i - 1][j - 1] << endl;
                    if (l100[k][l] - l100[k][j - 1] - l100[i - 1][l] + l100[i - 1][j - 1] == 0) {
                        ;
                        if (ps100[k][l] - ps100[k][j - 1] - ps100[i - 1][l] + ps100[i - 1][j - 1] > 0) {
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    cout << cnt << endl;
}