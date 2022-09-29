#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int g[501][501];
int n100[501][501];
int ns100[501][501];
int main() {
    memset(n100, 0, sizeof(n100));
    memset(ns100, 0, sizeof(ns100));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            n100[i][j] = n100[i - 1][j] + n100[i][j - 1] - n100[i - 1][j - 1] + (int)(g[i][j] == 100);
            ns100[i][j] = ns100[i - 1][j] + ns100[i][j - 1] - ns100[i - 1][j - 1] + (int)(g[i][j] < 100);
            // cout << n100[i][j] << ' ';
        }
        // cout << endl;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = i; k <= n; k++) {
                for (int l = j; l <= n; l++) {
                    if (n100[k][l] - n100[k][j - 1] - n100[i - 1][l] + n100[i - 1][j - 1] > 0 &&
                        ns100[k][l] - ns100[k][j - 1] - ns100[i - 1][l] + ns100[i - 1][j - 1] == 0) {
                        // cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}