#include <bits/stdc++.h>
using namespace std;
int n;
int a[101];
int b[101];
int cows[101];
int ncows[101];
string id[101];
int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cows[i] = b[i];
        // cout << cows[i] << ' ';
    }
    // cout << endl;
    for (int i = 1; i <= n; i++) {
        ncows[i] = cows[b[i]];
        // cout << ncows[i] << ' ';
    }
    // cout << endl;
    for (int i = 1; i <= n; i++) {
        cows[i] = ncows[b[i]];
        // cout << cows[i] << ' ';
    }
    // cout << endl;
    for (int i = 1; i <= n; i++) {
        cin >> id[cows[i]];
    }
    for (int i = 1; i <= n; i++) {
        cout << id[i] << endl;
    }
}