#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> turnon[101][101];
int n, m;
bool on[102][102];
bool disc[102][102];
void flood(int row, int col) {
    if (disc[row][col]) return;
    disc[row][col] = 1;
    for (pair<int, int> &p : turnon[row][col]) {
        on[p.first][p.second] = 1;
        if (disc[p.first - 1][p.second] || disc[p.first][p.second - 1] || disc[p.first + 1][p.second] || disc[p.first][p.second + 1]) {
            flood(p.first, p.second);
        }
    }
    if (on[row - 1][col]) flood(row - 1, col);
    if (on[row + 1][col]) flood(row + 1, col);
    if (on[row][col - 1]) flood(row, col - 1);
    if (on[row][col + 1]) flood(row, col + 1);
}
int main() {
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    cin >> n >> m;
    {
        int a, b, c, d;
        while (m--) {
            cin >> a >> b >> c >> d;
            turnon[a][b].push_back(make_pair(c, d));
        }
    }
    memset(on, 0, sizeof(on));
    on[1][1] = 1;
    memset(disc, 0, sizeof(disc));
    flood(1, 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cnt += on[i][j];
        }
    }
    cout << cnt << endl;
}