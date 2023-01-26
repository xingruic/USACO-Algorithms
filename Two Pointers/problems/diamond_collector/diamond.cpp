#include <algorithm>
#include <iostream>
using namespace std;
int n, k;
int a[50001];
int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    int ans = 0;
    int l = 1, r = 1;
    int m;
    int m1 = 0;
    int l1, r1;
    while (l <= n && r <= n) {
        m = k + a[l];
        while (r < n && a[r + 1] <= m) {
            r++;
        }
        if (r - l + 1 >= m1) {
            m1 = r - l + 1;
            l1 = l, r1 = r;
        }
        l++;
    }
    ans += m1;
    for (int i = 1; i + r1 <= n; i++) {
        a[l1 - 1 + i] = a[r1 + 1];
    }
    n -= m1;
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    l = 1, r = 1;
    m1 = 0;
    while (l <= n && r <= n) {
        m = k + a[l];
        while (r < n && a[r + 1] <= m) {
            r++;
        }
        if (r - l + 1 >= m1) {
            m1 = r - l + 1;
            l1 = l, r1 = r;
        }
        l++;
    }
    // cout << m1 << endl;
    cout << ans + m1 << endl;
}