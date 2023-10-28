#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
int n;
bool path[101][101];
int main() {
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    memset(path, 0, sizeof(path));
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        path[a][b] = 1;
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        int j;
        for (j = 1; j <= n && !path[i][j]; j++);
        if (j > n) {
            if (ans >= 0) {
                cout << -1 << endl;
                return 0;
            }
            ans = i;
        }
    }
    cout << ans << endl;
}