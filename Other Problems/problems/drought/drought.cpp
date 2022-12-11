#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int cows[10000];
int main() {
    // freopen("drought.out", "w", stdout);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> cows[i];
        }
        long long cnt = 0;
        for (int i = 1; i < n - 1; i++) {
            if (cows[i] > cows[i - 1]) {
                int x = min(cows[i + 1], cows[i] - cows[i - 1]);
                cows[i] -= x;
                cows[i + 1] -= x;
                cnt += x * 2;
            }
            // for (int i = 0; i < n; i++)
            //     cout << cows[i] << ' ';
            // cout << endl;
        }
        // cout << endl;
        for (int i = n - 2; i > 0; i--) {
            if (cows[i] > cows[i + 1]) {
                int x = min(cows[i - 1], cows[i] - cows[i + 1]);
                cows[i] -= x;
                cows[i - 1] -= x;
                cnt += x * 2;
            }
            // for (int i = 0; i < n; i++)
            //     cout << cows[i] << ' ';
            // cout << endl;
        }
        bool equal = 1;
        for (int i = 1; i < n; i++)
            if (cows[i] != cows[i - 1]) {
                equal = 0;
                break;
            }
        if (equal)
            cout << cnt << endl;
        else
            cout << -1 << endl;
    }
}