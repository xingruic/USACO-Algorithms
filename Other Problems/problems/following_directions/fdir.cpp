#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int n;
bool field[1501][1501]; // 1-indexed NxN field, 1=R, 0=D
int iedge[1501]; // field[i][n+1] (the rightmost column of vats)
int jedge[1501]; // field[n+1][j] (the bottom row of vats)
int cost[1501][1501]; // cost of stuff
queue<pair<int, int>> flips;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c = ' ';
            while (c != 'R' && c != 'D')
                c = getchar();
            field[i][j] = (c == 'R');
        }
        cin >> jedge[i];
    }
    for (int j = 1; j <= n; j++)
        cin >> iedge[j];
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        flips.push(make_pair(x, y));
    }
    for (int i = n; i > 0; i--) {
        for (int j = n; j > 0; j--) {
            if (i == n && !field[i][j]) {
                cost[i][j] = iedge[j];
                continue;
            }
            if (j == n && field[i][j]) {
                cost[i][j] = jedge[i];
                continue;
            }
            if (i < n) {
                if (j < n)
                    cost[i][j] = field[i][j] ? cost[i][j + 1] : cost[i + 1][j];
                else
                    cost[i][j] = cost[i + 1][j];
                continue;
            }
            if (j < n)
                cost[i][j] = cost[i][j + 1];
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            sum += cost[i][j];
    cout << sum << endl;
    for (int t = 0; t < q; t++) {
        auto coords = flips.front();
        flips.pop();
        int x = coords.first, y = coords.second;
        field[x][y] = !field[x][y];
        for (int i = x; i > 0; i--) {
            for (int j = y; j > 0; j--) {
                if (i == n && !field[i][j]) {
                    cost[i][j] = iedge[j];
                    continue;
                }
                if (j == n && field[i][j]) {
                    cost[i][j] = jedge[i];
                    continue;
                }
                if (i < n) {
                    if (j < n)
                        cost[i][j] = field[i][j] ? cost[i][j + 1] : cost[i + 1][j];
                    else
                        cost[i][j] = cost[i + 1][j];
                    continue;
                }
                if (j < n) {
                    cost[i][j] = cost[i][j + 1];
                }
            }
        }
        // cout << endl
        //      << x << ' ' << y << endl;
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         cout << field[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++)
        //         cout << cost[i][j] << '\t';
        //     cout << jedge[i] << endl;
        // }
        // for (int j = 1; j <= n; j++)
        //     cout << iedge[j] << '\t';
        int sum = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                sum += cost[i][j];
        cout << sum << endl;
    }
}