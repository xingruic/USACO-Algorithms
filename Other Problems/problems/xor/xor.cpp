/*************************************
 * Notes for XOR
 * operator^ is bitwise xor
 * you can use prefix sums for arrays
 * because the opposite of xor is xor itself, instead of subtracting, just xor the previous part off
 **************************************/
#include <bits/stdc++.h>
using namespace std;
int n, q;
int x[200001];
int sum[200001];
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    sum[1] = x[1];
    for (int i = 2; i <= n; i++)
        sum[i] = sum[i - 1] ^ x[i];
    int a, b;
    for (int i = 1; i <= q; i++) {
        cin >> a >> b;
        if (a > 1)
            cout << (sum[b] ^ sum[a - 1]) << '\n';
        else
            cout << sum[b] << '\n';
    }
}