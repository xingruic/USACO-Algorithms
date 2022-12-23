#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001];
bool prime[5000001];
bool make_four[5000001];
int t;
int prime_smaller(int x) {
    int i;
    for (i = x; !prime[i] || make_four[x - i]; i--)
        ;
    return i;
}
int main() {
    // freopen("out.txt", "w", stdout);
    memset(make_four, 0, sizeof(make_four));
    memset(prime, 1, sizeof(prime));
    memset(a, 0, sizeof(a));
    prime[0] = 0;
    make_four[1] = 1;
    for (int i = 2; i * i <= 5000000; i++) {
        if (i >= 5)
            make_four[i] = prime[i - 4];
        if (!prime[i])
            continue;
        for (int j = i; i * j <= 5000000; j++) {
            prime[i * j] = 0;
        }
    }
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int i;
        for (i = 1;; i++) {
            if (i > n)
                i = 1;
            if (a[i] == 0)
                break;
            if (prime[a[i]]) {
                cout << "Farmer John" << endl;
                break;
            } else if (make_four[a[i]]) {
                a[i] = 2;
            } else {
                a[i] -= prime_smaller(a[i]);
                a[i] -= prime_smaller(a[i]);
            }
            // cout << i << ' ' << a[i] << endl;
        }
        if (a[i] == 0)
            cout << "Farmer Nhoj" << endl;
    }
}