#include <bits/stdc++.h>
using namespace std;
int n;
int p[100000], t[100000];
int diff[100000]; // p minus t
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        diff[i] = p[i] - t[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        while (diff[i] != 0) {
            int j;
            int m = diff[i];
            for (j = i + 1; j < n && signbit(diff[j]) == signbit(diff[i]) && diff[j] != 0; j++) {
                if (signbit(diff[i]))
                    m = max(m, diff[j]);
                else
                    m = min(m, diff[j]);
            }
            j--;
            for (int k = i; k <= j; k++) {
                diff[k] -= m;
                t[k] += m;
            }
            cnt += abs(m);
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << t[i] << ' ';
    // }
    // cout << endl;
    cout << cnt << endl;
}