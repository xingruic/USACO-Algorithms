#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

int n, m;
typedef long long ll;
ll k;
ll grid[21][21];

ll cnt = 0;

set<ll> xsums[21];

void xsumsgen(int x, int y, ll xsum = 0) {
    xsum ^= grid[x][y];
    if (x == n / 2) {
        xsums[y].insert(xsum);
    }
    if (x > n / 2) xsumsgen(x - 1, y, xsum);
    if (y > 1) xsumsgen(x, y - 1, xsum);
}

void visit(int x, int y, ll xsum = 0) {
    if (x == n / 2) {
        cout << y << ' ' << xsum << endl;
        for (ll i : xsums[y]) {
            cnt += ((xsum ^ i) == k);
        }
    }
    xsum ^= grid[x][y];
    if (x < n / 2) visit(x + 1, y, xsum);
    if (y < m) visit(x, y + 1, xsum);
}

int main() {
    freopen("out.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> grid[i][j];
    xsumsgen(n, m);
    for (int i = 1; i <= m; i++) {
        for (ll j : xsums[i]) cout << j << ' ';cout << endl;
    }cout << endl;
    visit(1, 1);
    cout << cnt << endl;
}