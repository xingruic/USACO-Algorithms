#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[200000]; // .first is time, .second is deadline
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    long long t = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        // cout << a[i].first << ' ' << a[i].second << endl;
        t += a[i].first;
        sum += a[i].second - t;
    }
    cout << sum << endl;
}