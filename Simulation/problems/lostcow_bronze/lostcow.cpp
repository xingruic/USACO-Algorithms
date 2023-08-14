#include <bits/stdc++.h>
using namespace std;
int x, y;
int main() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    cin >> x >> y;
    int cnt = 0;
    bool r = y > x;
    for (int t = 1;; t *= 4) {
        if (r && y <= x + t) {
            cnt += y - x + t / 2;
            cout << cnt << endl;
            return 0;
        }
        cnt += t + t / 2;
        if (!r && y >= x - 2 * t) {
            cnt += x - y + t;
            cout << cnt << endl;
            return 0;
        }
        cnt += t * 3;
    }
}