#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int s[10000], v[10000]; // size and value
int n, m; // number of different items and size of knapsack
int dp[10000][10000];
int f() { // avail=number of units of available space, sum=sum of all selected
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= s[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - s[i]] + v[i]);
        }
    }
    return dp[n][m];
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> s[i] >> v[i];
    cout << f() << endl;
}