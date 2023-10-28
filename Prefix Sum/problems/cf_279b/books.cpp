#include<iostream>
// #include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1e5;
int n;
int t;
int a[maxn];
int psum[maxn];
void calc_psums() {
    psum[0] = a[0];
    bool st = a[0] <= t;
    for (int i = 1; i < n; i++) {
        st |= (a[i] <= t);
        psum[i] = psum[i - 1] + a[i];
    }
    if (!st) {
        cout << 0 << endl;
        exit(0);
    }
}
int binsearch(int l, int r, int i1) {
    if (l == r) {
        return l + 1;
    }
    int m = (l + r) / 2 + 1;
    int time_read = i1 > 0 ? psum[i1 + m] - psum[i1 - 1] : psum[m];
    if (time_read > t) {
        return binsearch(l, m - 1, i1);
    } else {
        return binsearch(m, r, i1);
    }
}
int main() {
    freopen("books.in", "r", stdin);
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    calc_psums();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(binsearch(0, n - i - 1, i), ans);
    }
    cout << ans << endl;
}