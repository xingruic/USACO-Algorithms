#include<bits/stdc++.h>
using namespace std;
int n;
bool a[101][101];
int main() {
    memset(a, 0, sizeof(a));
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)a[i][i] = 1;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    for (int j = 1; j <= n; j++)
        for (int i = 1; i <= n; i++)
            for (int k = 1; k <= n; k++) {
                if (a[i][j] && a[j][k]) a[i][k] = 1;
            }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << a[i][j] << ' ';
    //     }cout << endl;
    // }
    int i;
    for (int j = 1; j <= n; j++) {
        i = 1;
        for (; i <= n; i++) {
            if (!a[i][j]) break;
        }
        if (i > n) {
            cout << j << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}