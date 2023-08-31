#include <bits/stdc++.h>
using namespace std;
int n, m;
struct cow {
    bool same;
    int p1, p2;
    cow(bool same = 0, int p1 = 0, int p2 = 0) : same(same), p1(p1), p2(p2) {}
} cows[100001];
set<int> edge[100001];
char grass[100001];
void dfs(int x) {
    for (const int &j : edge[x]) {
        if (grass[j] == 'X') {
            grass[j] = !grass[x];
            dfs(j);
        }
    }
    for (const int &j : edge[x]) {
        if (grass[j] == grass[x]) {
            cout << 0 << endl;
            exit(0);
        }
    }
}
int main() {
    memset(grass, 'X', sizeof(grass));
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    cin >> n >> m;
    char c;
    for (int i = 1; i <= m; i++) {
        cin >> c >> cows[i].p1 >> cows[i].p2;
        cows[i].same = c == 'S';
    }
    for (int i = 1; i <= m; i++) {
        if (!cows[i].same) {
            edge[cows[i].p1].insert(cows[i].p2);
            edge[cows[i].p2].insert(cows[i].p1);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (cows[i].same) {
            for (const int &j : edge[cows[i].p1]) {
                edge[cows[i].p1].erase(j);
                edge[j].erase(cows[i].p1);
                edge[cows[i].p2].insert(j);
                edge[j].insert(cows[i].p2);
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (const int &j : edge[i]) {
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!edge[i].empty() && grass[i] == 'X') {
            cnt++;
            grass[i] = 1;
            dfs(i);
        }
    }
    cout << 1;
    while (cnt--)
        cout << 0;
    cout << endl;
}