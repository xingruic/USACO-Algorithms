#include <bits/stdc++.h>
using namespace std;
int n, r[1001];
int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    memset(r, 0, sizeof(r));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    int mcnt = 0x7fffffff;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (j > i)
                cnt += (j - i) * r[j];
            if (j < i)
                cnt += (j + n - i) * r[j];
        }
        // cout << cnt << endl;
        mcnt = min(mcnt, cnt);
    }
    cout << mcnt << endl;
    return 0;
}