#include <cstring>
#include <iostream>
using namespace std;
int n, W;
int w[251], t[251];
int dp[251][1001];
int main() {
    memset(dp, 0x7f, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> t[i];
    }
    
    return 0;
}