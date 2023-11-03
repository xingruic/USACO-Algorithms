#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
int n, k;
vector<int> col[10];
vector<int> flood[10];
void ffill(int x, int y, int f) {
    if (flood[x][y] != -1) return;
    flood[x][y] = f;
    int cur = col[x][y];
    if (x > 0 && col[x - 1][y] == cur) {
        ffill(x - 1, y, f);
    }
    if (y > 0 && col[x][y - 1] == cur) {
        ffill(x, y - 1, f);
    }
    if (x < 9 && col[x + 1][y] == cur) {
        ffill(x + 1, y, f);
    }
    if (y < n - 1 && col[x][y + 1] == cur) {
        ffill(x, y + 1, f);
    }
}
int main() {
    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);
    cin >> n >> k;
    char c;
    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < 10; j++) {
            c = getchar();
            col[j].push_back(c - '0');
        }
    }
    for (int i = 0; i < 10; i++)
        reverse(col[i].begin(), col[i].end());
    vector<int> *cnt = new vector<int>();
    int del = 1;
    while (del > 0) {
        int fnum = 0;
        for (int i = 0; i < 10; i++) {
            flood[i].assign(n, -1);
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < n; j++) {
                if (flood[i][j] == -1 && col[i][j] > 0) {
                    ffill(i, j, fnum++);
                }
            }
        }
        cnt->clear();
        cnt->resize(fnum);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < n; j++) {
                (*cnt)[flood[i][j]]++;
            }
        }
        del = 0;
        for (int u = 0; u < fnum; u++) {
            if ((*cnt)[u] >= k) {
                // cout << u << ' ';
                del++;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < n; j++) {
                        if (flood[i][j] == u) {
                            col[i][j] = -1;
                        }
                    }
                }
            }
        }
        // cout << endl;
        for (int i = 0; i < 10; i++) {
            col[i].erase(remove(col[i].begin(), col[i].end(), -1), col[i].end());
            col[i].resize(n);
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0;j < 10; j++) cout << flood[j].at(i) << '\t';
        //     cout << endl;
        // }
        // cout << endl;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0;j < 10; j++) cout << col[j].at(i) << '\t';
        //     cout << endl;
        // }
        // cout << endl << "=============================================" << endl << endl;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0;j < 10; j++) cout << col[j].at(i);
        cout << endl;
    }
}