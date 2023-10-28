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
    for (int i = 1; i < n; i++) {
        psum[i] = psum[i - 1] + a[i];
    }
}
int main() {
    // freopen("books.in", "r", stdin);
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    calc_psums();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = i; j < n; j++) {
            if ((i > 0 ? psum[j] - psum[i - 1] : psum[j]) > t) break;
        }
        ans = max(ans, j - i);
    }
    cout << ans << endl;
}