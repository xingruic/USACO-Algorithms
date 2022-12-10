#include <bits/stdc++.h>
using namespace std;
int n;
int dist[1001][1001], x[1001], y[1001]; // dist[i][j] is the SQUARED distance between i and j
int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    memset(dist, -1, sizeof(dist));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int a = x[i] - x[j], b = y[i] - y[j];
            dist[i][j] = dist[j][i] = a * a + b * b;
        }
    }
    for (int i = 1; i <= n; i++) {
        int x = 0, m = 0x7fffffff;
        for (int j = i + 1; j <= n; j++) {
            if (dist[i][j] > m)
                dist[i][j] = dist[j][i] = -1;
            else if (dist[i][j] < m) {
                dist[i][x] = dist[x][i] = -1;
                m = dist[i][j], x = j;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans = max(ans, dist[i][j]);
            // cout << dist[i][j] << ' ';
        }
        // cout << endl;
    }
    cout << ans << endl;
}