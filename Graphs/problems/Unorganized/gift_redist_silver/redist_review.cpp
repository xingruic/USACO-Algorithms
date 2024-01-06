#include<bits/stdc++.h>
using namespace std;
int n, wish[501][501];
int best[501];
bool done[501];
int better(int x, int i) {
    for (int j = 1; wish[x][j] != x; j++) {
        if (wish[x][j] == i) return i;
    }
    return x;
}
bool loops(int x, int orig) {
    if (done[x]) return 0;
    done[x] = 1;
    for (int i = 1; i < n; i++) {
        if (wish[x][i] == x) break;
        if (wish[x][i] == orig) {
            best[x] = better(x, wish[x][i]);
            return 1;
        }
        if (loops(i, orig)) {
            best[x] = better(x, wish[x][i]);
        }
    }
    return 0;
}
void doloops() {
    memset(done, 0, sizeof(done));
    for (int i = 1; i <= n; i++) {
        loops(i, i);
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        best[i] = i;
        for (int j = 1; j <= n; j++) {
            cin >> wish[i][j];
        }
    }
    doloops();
    for (int i = 1; i <= n; i++) cout << best[i] << endl;
}