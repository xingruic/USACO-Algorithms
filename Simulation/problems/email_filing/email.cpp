#include <bits/stdc++.h>
using namespace std;
int t;
int m, n, k;
vector<int> f;
int last(int minf, int maxf) {
    for (int i = f.size() - 1; i > 0; i--) {
        if (f[i] >= minf && f[i] < maxf)
            return i;
    }
    return 0x7fffffff;
}
int main() {
    freopen("email.out", "w", stdout);
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        f.clear();
        f.push_back(0);
        cin >> m >> n >> k;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            f.push_back(x);
        }
        int posn = 1;
        for (int fol = 1; fol <= m; fol += k) {
            int efol = min(fol + k, m + 1);
            int cur;
            int prev = 0x7fffffff;
            while (posn < f.size() && last(fol, efol) != 0x7ffffff) {
                while (prev > (cur = last(fol, efol))) {
                    prev = cur;
                    for (int i = posn; i < posn + k; i++) {
                        while (i < f.size() && f[i] >= fol && f[i] < efol) {
                            f.erase(f.begin() + i);
                        }
                    }
                }
                posn++;
            }
            if (posn > f.size())
                posn = f.size() - 1;
        }
        cout << "posn " << posn << endl;
        for (int i = 1; i < f.size(); i++) {
            cout << f[i] << ' ';
        }
        cout << endl;
        if (f.size() > 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}