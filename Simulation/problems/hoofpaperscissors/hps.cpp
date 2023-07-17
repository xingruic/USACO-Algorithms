#include <bits/stdc++.h>
using namespace std;
int n;
int p[101], q[101];
bool t1(int num) {
    switch (p[num]) {
    case 1:
        if (q[num] == 2)
            return 1;
        break;
    case 2:
        if (q[num] == 3)
            return 1;
        break;
    default:
        if (q[num] == 1)
            return 1;
        break;
    }
    return 0;
}
int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> q[i];
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i] == q[i])
            continue;
        bool t = t1(i);
        cnt1 += (t);
        cnt2 += (!t);
        // cout << t << endl;
    }
    cout << max(cnt1, cnt2) << endl;
}