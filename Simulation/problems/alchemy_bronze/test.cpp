#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int main() {
    int x;
    for (int i = 0; i < 100; i++) {
        cin >> x;
        ans += x;
    }
    cout << ans << endl;
}