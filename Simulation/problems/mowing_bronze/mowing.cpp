#include <bits/stdc++.h>
using namespace std;
int n;
pair<char, int> step[100];
int last[2001][2001];
int main() {
    memset(last, -1, sizeof(last));
    last[1000][1000] = 0;
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> step[i].first >> step[i].second;
    }
    int minx = 0x7fffffff;
    int x = 1000, y = 1000;
    bool crossed = 0;
    // cout << x - 1000 << ' ' << y - 1000 << endl;
    for (int i = 0, t = 0; i < n; i++) {
        switch (step[i].first) {
        case 'N':
            for (int j = y + 1; j <= y + step[i].second; j++) {
                // cout << last[x][j] << ' ';
                t++;
                if (last[x][j] > -1) {
                    crossed = 1;
                    minx = min(minx, t - last[x][j]);
                }
                last[x][j] = t;
                // cout << last[x][j] << endl;
            }
            y += step[i].second;
            // cout << x - 1000 << ' ' << y - 1000 << endl;
            break;
        case 'S':
            for (int j = y - 1; j >= y - step[i].second; j--) {
                // cout << last[x][j] << ' ';
                t++;
                if (last[x][j] > -1) {
                    crossed = 1;
                    minx = min(minx, t - last[x][j]);
                }
                last[x][j] = t;
                // cout << last[x][j] << endl;
            }
            y -= step[i].second;
            // cout << x - 1000 << ' ' << y - 1000 << endl;
            break;
        case 'E':
            for (int j = x + 1; j <= x + step[i].second; j++) {
                // cout << last[j][y] << ' ';
                t++;
                if (last[j][y] > -1) {
                    crossed = 1;
                    minx = min(minx, t - last[j][y]);
                }
                last[j][y] = t;
                // cout << last[j][y] << endl;
            }
            x += step[i].second;
            // cout << x - 1000 << ' ' << y - 1000 << endl;
            break;
        case 'W':
            for (int j = x - 1; j >= x - step[i].second; j--) {
                // cout << last[j][y] << ' ';
                t++;
                if (last[j][y] > -1) {
                    crossed = 1;
                    minx = min(minx, t - last[j][y]);
                }
                last[j][y] = t;
                // cout << last[j][y] << endl;
            }
            x -= step[i].second;
            // cout << x - 1000 << ' ' << y - 1000 << endl;
            break;
        default:
            break;
        }
        // cout << t << ' ' << x - 1000 << ' ' << y - 1000 << endl;
    }
    if (!crossed) {
        cout << -1 << endl;
    } else
        cout << minx << endl;
}