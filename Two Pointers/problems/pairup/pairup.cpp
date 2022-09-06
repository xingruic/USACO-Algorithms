#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> milk;
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}
int main() {
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        milk.push_back(make_pair(y, x));
    }
    sort(milk.begin(), milk.end());
    vector<pair<int, int>>::iterator a = milk.begin();
    vector<pair<int, int>>::iterator b = milk.end();
    b--;
    int ans = 0;
    while (a < b) {
        if ((*a).second < (*b).second) {
            ans = max(ans, (*a).first + (*b).first);
            (*b).second -= (*a).second;
            a++;
        } else if ((*a).second > (*b).second) {
            ans = max(ans, (*a).first + (*b).first);
            (*a).second -= (*b).second;
            b--;
        } else {
            ans = max(ans, (*a).first + (*b).first);
            a++;
            b--;
        }
    }
    cout << ans << endl;
}