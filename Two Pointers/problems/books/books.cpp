#include <algorithm>
#include <iostream>
using namespace std;
int n, t;
int a[100000];
int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, r = 0, sum = 0;
    int ans = 0;
    while (l < n && r < n) {
        while (r < n) {
            if ((sum += a[r]) <= t)
                r++;
            else {
                sum -= a[r];
                break;
            }
        }
        ans = max(ans, r - l);
        sum -= a[l];
        l++;
    }
    // cerr << l << ' ' << r << endl;
    cout << ans << endl;
}