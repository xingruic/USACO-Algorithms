#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100000], b[100000];
int compress(int x) {
    int l = 0, r = n - 1;
    while (l != r) {
        if (a[(l + r) / 2] < x) {
            r = (l + r) / 2 - 1;
        } else if (a[(l + r) / 2] > x) {
            l = (l + r) / 2 + 1;
        } else {
            return (l + r) / 2;
        }
    }
    return l;
}
bool wifi[100000] = {0};
int main() {
    freopen("cellnet.in", "r", stdin);
    freopen("cellnet.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(b, b + m);
    sort(a, a + n);
    int r = 0;
    while (1) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
            }
        }
    }
}