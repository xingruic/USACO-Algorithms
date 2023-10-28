#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n;
int r, c;
char grid[51][51];
vector<pair<int, int>> island[16];
bool adjacent;
int adji, adjj;
void adjacent_to(char c, int i, int j) {
    adjacent = 1;
    adji = i, adjj = j;
    if (i > 1 && grid[i - 1][j] == c) {
        adji--;
        return;
    }
    if (j > 1 && grid[i][j - 1] == c) {
        adjj--;
        return;
    }
    if (i < n && grid[i + 1][j] == c) {
        adji++;
        return;
    }
    if (j < n && grid[i][j + 1] == c) {
        adjj++;
        return;
    }
    adjacent = 0;
}
int main() {
    freopen("island.in", "r", stdin);
    freopen("island.out", "w", stdout);
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> grid[i][j];
    try {
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (grid[i][j] == 'X') {
                    n = 1;
                    grid[i][j] = 1;
                    island[n].push_back(make_pair(i, j));
                    throw 1;
                }
            }
        }
    } catch (int k) {}
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (grid[i][j] == 'X') {
                adjacent_to(n, i, j);
                if (adjacent) {
                    grid[i][j] = n;
                } else {
                    grid[i][j] = ++n;
                }
                island[n].push_back(make_pair(i, j));
            }
        }
    }
    // for (int i = 1; i <= r; i++) {
    //     for (int j = 1; j <= c; j++) cout << (int)grid[i][j] << '\t';
    //     cout << endl;
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (pair<int, int> &j : island[i]) {
    //         cout << '(' << j.first << ',' << j.second << ") ";
    //     }cout << endl;
    // }

}