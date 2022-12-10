#include <bits/stdc++.h>
using namespace std;
int n;
int s[101], t[101], b[101];
int cnt[1001];
int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i] >> t[i] >> b[i];
    int maxt = 0;
    for (int i = 1; i <= n; i++) {
        maxt = max(maxt, t[i]);
        for (int j = s[i]; j <= t[i]; j++) {
            cnt[j] += b[i];
        }
    }
    int maxcnt = 0;
    for (int i = 1; i <= maxt; i++) {
        maxcnt = max(maxcnt, cnt[i]);
    }
    cout << maxcnt << endl;
}