#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[101];
vector<int> recipe[101];
void make_metal(int x) {
    if (recipe[x].size() == 0) {
        return;
    }
    for (int i = 0; i < recipe[x].size(); i++) {
        if (a[recipe[x][i]] == 0) {
            make_metal(recipe[x][i]);
            if (a[recipe[x][i]] == 0)
                return;
        }
    }
    a[x]++;
    for (int i = 0; i < recipe[x].size(); i++) {
        a[recipe[x][i]]--;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("alchemy.in", "r", stdin);
    // freopen("alchemy.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int l, m, x;
        cin >> l >> m;
        while (m--) {
            cin >> x;
            recipe[l].push_back(x);
        }
    }
    int prev_n = -1;
    while (a[n] > prev_n) {
        prev_n = a[n];
        make_metal(n);
    }
    cout << a[n] << endl;
}