#include <cstring>
#include <iostream>
using namespace std;
int n, m;
bool a[20001][20001];
int main() {
    memset(a, 0, sizeof(a));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= n; k++) {
                if (a[i][j] && a[j][k])
                    a[i][k] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                continue;
            if (!a[i][j]) {
                cout << "NO\n"
                     << i << ' ' << j << '\n';
                exit(0);
            }
        }
    }
    cout << "YES\n";
}