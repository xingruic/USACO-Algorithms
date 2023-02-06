#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int n, x;
int c[101];
int dp[101][1000001];
int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= x; j++)
    //         cout << dp[i][j] << ' ';
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (c[i] <= j) {
                dp[i][j] += dp[i][j - c[i]];
            }
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % 1000000007;
        }
    }
    cout << dp[n][x] << endl;
}