#include <bits/stdc++.h>
using namespace std;
int a, b;
int n[100];
int m[100];
int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    cin >> a >> b;
    int x, y;
    int start = 0;
    for (int i = 0; i < a; i++) {
        cin >> x >> y;
        for (int j = start; j < start + x; j++)
            n[j] = y;
        start += x;
    }
    start = 0;
    for (int i = 0; i < b; i++) {
        cin >> x >> y;
        for (int j = start; j < start + x; j++)
            m[j] = y;
        start += x;
    }
    int maxover = 0;
    for (int i = 0; i < 100; i++) {
        maxover = max(maxover, m[i] - n[i]);
    }
    cout << maxover << endl;
}