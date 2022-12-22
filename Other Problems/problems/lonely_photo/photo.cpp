#include <bits/stdc++.h>
using namespace std;
int n;
char s[50005];
int hpsum[50005], gpsum[50005];
int main() {
    cin >> n;
    cin >> s;
    memset(hpsum, 0, sizeof(hpsum));
    memset(gpsum, 0, sizeof(gpsum));
    hpsum[0] = (s[0] == 'H');
    gpsum[0] = (s[0] == 'G');
    for (int i = 1; i < n; i++) {
        hpsum[i] = hpsum[i - 1] + (s[i] == 'H');
        gpsum[i] = gpsum[i - 1] + (s[i] == 'G');
    }
    // for (int i = 0; i < n; i++) {
    //     cout << hpsum[i] << ' ' << gpsum[i] << endl;
    // }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 2; j < n; j++) {
            if (
                (hpsum[j] - hpsum[i] + (s[i] == 'H')) == 1 ||
                (gpsum[j] - gpsum[i] + (s[i] == 'G')) == 1) {
                // cout << i << ' ' << j << endl;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}