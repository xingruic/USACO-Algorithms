#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int maxn = 101;
int n;
int f[maxn];
int root(int x) {
    if (f[x] == x) {
        return x;
    } else {
        return f[x] = root(f[x]);
    }
}
int main() {
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    for (int i = 1; i <= maxn; i++) {
        f[i] = i;
    }
    cin >> n;
    for (int i = n - 1; i--;) {
        int a, b;
        cin >> a >> b;
        f[a] = b;
    }
    for (int i = 1; i <= n; i++) {
        root(i);
        // cout << f[i] << ' ';
    }
    sort(f + 1, f + 1 + n);
    f[0] = f[1];
    for (int i = 1; i <= n; i++) {
        if (f[i] != f[i - 1]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << f[0] << endl;
}