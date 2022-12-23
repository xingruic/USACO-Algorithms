#include <bits/stdc++.h>
using namespace std;
int n;
unsigned r[301][301];
unsigned a[301];
unsigned min_[301][301], max_[301][301];
bool check() {
    memset(min_, 0x7f, sizeof(min_));
    memset(max_, 0, sizeof(max_));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = i; k <= n; k++) {
                min_[j][k] = min(min_[j][k], a[i]);
                max_[j][k] = max(max_[j][k], a[i]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (r[i][j] != max_[i][j] - min_[i][j])
                return 0;
        }
    }
    return 1;
}
void find(int i = 1) {
    if (i == n) {
        // cout << "ok" << endl;
        if (check()) {
            for (int j = 1; j < n; j++) {
                cout << a[j] << ' ';
            }
            cout << a[n] << endl;
            exit(0);
        }
        return;
    }
    a[i + 1] = a[i] + 2;
    find(i + 1);
    if (a[i] > 1) {
        a[i + 1] = a[i] - 2;
        find(i + 1);
    }
    a[i + 1] = a[i] + 1;
    find(i + 1);
    a[i + 1] = a[i];
    find(i + 1);
    if (a[i] > 0) {
        a[i + 1] = a[i] - 1;
        find(i + 1);
    }
    return;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) {
            cin >> r[i][j];
        }
    a[1] = 1;
    find();
}