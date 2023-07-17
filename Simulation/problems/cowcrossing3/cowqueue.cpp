#include <bits/stdc++.h>
using namespace std;
int n;
struct cow {
    int a, q, f = 0;
} cows[101];
int main(int argc, char **argv) {
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cows[i].a >> cows[i].q;
    }
    sort(cows + 1, cows + n + 1, [](cow &l, cow &r) { return l.a < r.a; });
    cows[1].f = cows[1].a + cows[1].q;
    for (int i = 2; i <= n; i++) {
        cows[i].f = max(cows[i].a, cows[i - 1].f) + cows[i].q;
    }
    // for (int i = 1; i <= n; i++)
    //     cout << cows[i].a << ' ' << cows[i].q << ' ' << cows[i].f << endl;
    cout << cows[n].f << endl;
}