#include <bits/stdc++.h>
using namespace std;
int n;
int p[200000];
int main() {
    // freopen("lengths.in", "r", stdin);
    // freopen("lengths.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p, p + n);
    int x = p[n / 2];
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(p[i] - x);
        // cout << abs(p[i] - x) << ' ';
    }
    // cout << endl
    //      << x << endl;
    cout << sum << endl;
}