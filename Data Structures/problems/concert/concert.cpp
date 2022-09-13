#include <bits/stdc++.h>
using namespace std;
int n, m;
multiset<int> h, t;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        auto y = h.upper_bound(x);
        if (y == h.begin())
            cout << -1 << endl;
        else {
            y--;
            cout << *y << endl;
            h.erase(y);
        }
    }
}