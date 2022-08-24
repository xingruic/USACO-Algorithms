#include <algorithm>
#include <iostream>
using namespace std;
int n;
int a[50001];
unsigned char sum[50001] = {0};
int main() {
    int t = clock();
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    cin >> n;
    sum[0] = a[0] % 7;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i + 1] = (sum[i] + a[i]) % 7;
    }
    int m = 0;
    int s = -1, e = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i + m + 1; j <= n; j++) {
            if ((sum[j] - sum[i]) % 7 == 0)
                m = j - i, s = i, e = j;
        }
    }
    cout << m << endl;
    cerr << (clock() - t) / 1000.0 << endl;
}