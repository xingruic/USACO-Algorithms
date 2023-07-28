#include<bits/stdc++.h>
using namespace std;
int m, n, k;
vector<int> f;
int main() {
    freopen("email.in", "r", stdin);
    freopen("email.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n >> k;
        f.resize(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> f[i];
            f[i]--; // remember to add back
        }
        int bottom = k;
        while (bottom > 0) {
            for (int i = bottom - k; i < n && i < bottom; i++) {
                if (f[i] >= bottom - k && f[i] < bottom) {
                    f.erase(next(f.begin(), i));
                    i--, n--;
                }
            }
            bottom++;
            if (bottom > n) bottom = n;
        }
        for (int &i : f) cout << i << endl;
    }
}