#include <bits/stdc++.h>
using namespace std;
int n;
int a[1001][1001];
int oddr[1001], oddc[1001], evenr[1001], evenc[1001]; // sums of the values with odd or even indices in rows or colums
                                                      // assumes i controlls row, j controlls column
int main() {
    memset(oddr, 0, sizeof(oddr));
    memset(oddc, 0, sizeof(oddc));
    memset(evenr, 0, sizeof(evenr));
    memset(evenc, 0, sizeof(evenc));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (i % 2)
                oddc[j] += a[i][j];
            else
                evenc[j] += a[i][j];
            if (j % 2)
                oddr[i] += a[i][j];
            else
                evenr[i] += a[i][j];
        }
    }
    int ans = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += max(oddr[i], evenr[i]);
    }
    ans = sum, sum = 0;
    for (int j = 1; j <= n; j++) {
        sum += max(oddc[j], evenc[j]);
    }
    ans = max(ans, sum);
    cout << ans << endl;
}