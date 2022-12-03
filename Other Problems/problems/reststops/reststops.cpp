#include <bits/stdc++.h>
using namespace std;
int l, n, f, b;
int x[100001], c[100001];
int main() {
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    cin >> l >> n >> f >> b;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> c[i];
    }
    int ans = 0;
    int dist = 0;
    for (int i = 1; i <= n; i++) {
        ans += (x[i] - dist) * (f - b) * c[i];
        dist = x[i];
    }
    cout << ans << endl;
}
