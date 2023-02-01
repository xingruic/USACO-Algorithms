#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, x;
int a[101];
int dp[1000001];
int main() {
    memset(dp, 0x7f, sizeof(dp));
    dp[0] = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j >= a[i])
                dp[j] = min(dp[j], dp[j - a[i]] + 1);
        }
    }
    // for (int i = 1; i <= x; i++)
    //     cout << dp[i] << endl;
    cout << (dp[x] == 0x7f7f7f7f ? -1 : dp[x]);
}