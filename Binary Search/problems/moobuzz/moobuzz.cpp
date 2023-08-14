#include<bits/stdc++.h>
using namespace std;
int n;
long long search(long long l, long long r) {
    long long x = (l + r) / 2;
    long long res = x - x / 3 - x / 5 + x / 15;
    if (res < n) return search(x + 1, r);
    if (res > n) return search(l, x);
    return x;
}
int main() {
    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);
    cin >> n;
    long long s = search(1, LONG_LONG_MAX);
    while (s % 3 == 0 || s % 5 == 0)
        s--;
    cout << s << endl;
}