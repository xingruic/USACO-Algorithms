#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
int n, r[301][301];
int rmax[301][301], rmin[301][301];
int a[301];
int main() {
    memset(r, 0, sizeof(r));
    memset(rmax, 0, sizeof(rmax));
    memset(rmin, 0, sizeof(rmin));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cin >> r[i][j];
            // r[j][i]=r[i][j];
        }
    }
    a[1] = 0;
    for (int u = 2; u <= n; u++) {
        a[u] = a[u - 1] + r[u - 1][u];
        for()
    }
}