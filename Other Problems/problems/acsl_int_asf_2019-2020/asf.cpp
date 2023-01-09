#include <bits/stdc++.h>
using namespace std;
string a, b;
void clearLikeChars(int &minlen) {
    for (int i = 0; i < minlen; i++) {
        if (a[i] == b[i]) {
            a.erase(i, 1), b.erase(i, 1);
            i--;
            minlen--;
        }
    }
}
int main() {
    // freopen("asf.out","w",stdout);
    for (int test = 0; test < 5; test++) {
        cin >> a >> b;
        int minlen = min(a.size(), b.size());
        clearLikeChars(minlen);
        // cout << a << ' ' << b << ' ' << minlen << endl;
        // int t = clock();
        for (int i = 0; i < minlen; i++) {
            bool f = 1;
            bool decr_i = 0;
            while (f) {
                if (i < 0)
                    i = 0;
                while (a[i] == b[i] && i < minlen) {
                    a.erase(i, 1);
                    b.erase(i, 1);
                    minlen--;
                }
                if (i >= minlen)
                    break;
                f = 0;
                if (i + 1 < b.size() && b[i + 1] == a[i]) {
                    b.erase(i, 1);
                    clearLikeChars(minlen);
                    f = 1;
                    decr_i = 1;
                }
                if (i + 1 < a.size() && a[i + 1] == b[i]) {
                    a.erase(i, 1);
                    clearLikeChars(minlen);
                    f = 1;
                    decr_i = 1;
                }
            }
            if (decr_i)
                i--;
            minlen = min(a.size(), b.size());
        }
        // cout << (clock() - t) * 1.0 / CLOCKS_PER_SEC << endl;
        int ans = 0;
        // cout<<a<<' '<<b<<endl;
        for (int i = 0; i < minlen; i++) {
            ans += a[i] - b[i];
        }
        ans += max(a.size(), b.size()) - minlen;
        cout << ans << endl;
    }
}
/*
DEFGHIJKMNO
LDZZHQJWX
*/