#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int n, m;
int a[200001], b[200001];
int kval[10002];
int ans[10001];
int main() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(kval, 0, sizeof(kval));
    // freopen("conv.in", "r", stdin);
    // freopen("conv.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n;i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            kval[a[i] + a[j]]++;
            kval[b[i] + b[j] + 1]--;
        }
    }
    ans[0] = kval[0];
    for (int i = 1; i <= m * 2; i++) {
        ans[i] = ans[i - 1] + kval[i];
    }
    for (int i = 0; i <= m * 2; i++) {
        cout << ans[i] << endl;
    }
}