#include <fstream>
#include <iostream>
using namespace std;
int n, q;
int a[500001];
long long sum[500001];
int main() {
    freopen("prefixsum.in", "r", stdin);
    freopen("prefixsum.out", "w", stdout);
    cin >> n >> q;
    sum[0] = a[0];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i + 1] = a[i] + sum[i];
    }
    int l, r;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        cout << sum[r] - sum[l] << endl;
    }
}