#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int maxn = 1000;
int N;
uint16_t grid[maxn][maxn];
void flood(int n, int i, int j) {
    grid[i][j] = n;
    if (i + 1 < N && grid[i + 1][j] == '#') flood(n, i + 1, j);
    if (i > 0 && grid[i - 1][j] == '#') flood(n, i - 1, j);
    if (j + 1 < N && grid[i][j + 1] == '#') flood(n, i, j + 1);
    if (j > 0 && grid[i][j - 1] == '#') flood(n, i, j - 1);
}
int area(int n) {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans += (grid[i][j] == n);
        }
    }
    return ans;
}
int perim(int n) {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] != '.') continue;
            if (i + 1 < N && grid[i + 1][j] == n) ans++;
            if (i > 0 && grid[i - 1][j] == n) ans++;
            if (j + 1 < N && grid[i][j + 1] == n) ans++;
            if (j > 0 && grid[i][j - 1] == n) ans++;
        }
    }
    for (int i = 0; i < N; i++) {
        if (grid[i][0] == n) ans++;
        if (grid[i][N - 1] == n) ans++;
        if (grid[0][i] == n) ans++;
        if (grid[N - 1][i] == n) ans++;
    }
    return ans;
}
int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            grid[i][j] = c;
        }
    }
    int nblob = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == '#') flood(nblob++, i, j);
        }
    }
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << (int)grid[i][j] << '\t';
    //     }cout << endl;
    // }
    int ma = -1, mp = 0x7fffffff;
    for (int i = 0; i < nblob; i++) {
        int a = area(i), p = perim(i);
        if (a > ma) {
            ma = a;
            mp = p;
        } else if (a == ma) {
            if (p < mp) mp = p;
        }
    }
    cout << ma << ' ' << mp << endl;
}