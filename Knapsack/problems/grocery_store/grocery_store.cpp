#include <cstring>
#include <iostream>
using namespace std;
int s, n, w[100001], v[100001], k[100001];
int dp[2001];
int main() {
    // freopen("debug.cerr", "w", stderr);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, 0, sizeof(dp));
    cin >> s >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> k[i];
    }
    // for (int i = 1; i <= n; i++)
    //     cerr << k[i] << ' ';
    // cerr << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = s; j >= 1; j--) {
            for (int l = 1, t = w[i], t2 = v[i]; l <= k[i] && t <= j; l++, t += w[i], t2 += v[i]) {
                dp[j] = max(dp[j], dp[j - t] + t2);
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= s; j++) {
    //         cerr << dp[i][j] << '\t';
    //     }
    //     cerr << endl;
    // }
    cout << dp[s] << '\n';
}