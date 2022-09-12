#include <bits/stdc++.h>
using namespace std;
int pokecnt['z' + 1];
int n;
char poketype[100000];
int main() {
    freopen("pokemon.in", "r", stdin);
    freopen("pokemon.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> poketype[i];
        pokecnt[poketype[i]]++;
    }
    int l = 0, r = n - 1;
    int ans = 0x7fffffff;
    while (l <= r) {
        ans = min(ans, r - l + 1);
        bool done = 1;
        if (pokecnt[poketype[l]] > 1) {
            pokecnt[poketype[l]]--;
            l++;
            done = 0;
        }
        if (pokecnt[poketype[r]] > 1) {
            pokecnt[poketype[r]]--;
            r--;
            done = 0;
        }
        if (done)
            break;
    }
    cout << ans << endl;
}