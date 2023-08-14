#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[251][251];
int b[251][251];
const int SIZE = 251 * 251;
pair<int, int> edges[25000];
int main() {
    fill(&a[0][0], &a[0][0] + SIZE, 0x3d3d3d3d);
    freopen("rblock.in", "r", stdin);
    freopen("rblock.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second >> a[edges[i].first][edges[i].second];
        a[edges[i].second][edges[i].first] = a[edges[i].first][edges[i].second];
    }
    copy(&a[0][0], &a[0][0] + SIZE, &b[0][0]);
    for (int k = 1; k <= n; k++) {
        for (int j = 1; j <= n; j++) {
            for (int l = 1; l <= n; l++) {
                if (b[j][k] + b[k][l] < b[j][l]) b[j][l] = b[j][k] + b[k][l];
            }
        }
    }
    int orig = b[1][n], maxmore = 0;
    // cout << orig << endl;
    for (int i = 0; i < m; i++) {
        copy(&a[0][0], &a[0][0] + SIZE, &b[0][0]);
        b[edges[i].first][edges[i].second] *= 2;
        b[edges[i].second][edges[i].first] *= 2;
        // for (int j = 1; j <= n; j++) {
        //     for (int k = 1; k <= n; k++) {
        //         cout << (b[j][k] == 0x7fffffff ? '-' : b[j][k]) << '\t';
        //     }cout << endl;
        // }cout << endl;
        for (int k = 1; k <= n; k++) {
            for (int j = 1; j <= n; j++) {
                for (int l = 1; l <= n; l++) {
                    if (b[j][k] + b[k][l] < b[j][l]) b[j][l] = b[l][j] = b[j][k] + b[k][l];
                }
            }
        }
        // cout << b[1][n] << endl;
        maxmore = max(b[1][n] - orig, maxmore);
    }
    cout << maxmore << endl;
}