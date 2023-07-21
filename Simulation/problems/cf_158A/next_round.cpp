#include <iostream>
using namespace std;
int main() {
    // freopen("hi.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    int i, j;
    int cnt = k - 1;
    for (i = 0; i < k - 1; i++) {
        cin >> j;
        if (j == 0) {
            cout << i << endl;
            return 0;
        }
    }
    // cout << cnt << endl;
    cin >> k;
    if (k == 0) {
        cout << i << endl;
        return 0;
    }
    j = 100;
    for (; i < n && j >= k; i++, cnt++) {
        cin >> j;
        // cout << j << ' ';
    }
    // cout << endl;
    cout << cnt << endl;
}