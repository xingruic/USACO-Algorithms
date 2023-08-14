#include<bits/stdc++.h>
using namespace std;
int els[50000], els2[50000], bes[50000];
int n;
int main() {
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> els[i];
    }
    memcpy(els2, els, sizeof(int) * n);
    sort(els2, els2 + n);
    int idx = 0;
    for (int i = 1; i < n; i++) {
        for (int j = els2[i - 1] + 1; j < els2[i]; j++) {
            bes[idx++] = j;
        }
    }
    for (int j = els2[n - 1] + 1; j <= 2 * n; j++) bes[idx++] = j;
    // for (int i = 0; i < n; i++) cout << bes[i] << ' ';
    // cout << endl;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (bes[j] > els[i]) {
                cnt++;
                bes[j] = -1;
                break;
            }
        }
    }
    cout << cnt << endl;
}