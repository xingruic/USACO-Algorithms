#include <bits/stdc++.h>
using namespace std;
int n;
int x[1001], y[1001];
int a[1001][1001];
bool visited[1001];
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    memset(visited, false, sizeof(visited));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
        }
    }
    int cnt = n;
    visited[1] = true;
    vector<pair<int, int>> v;
    for (int i = 2; i <= n; i++) {
        if (!visited[i]) {
            v.push_back(make_pair(i, a[1][i]));
        }
    }
    int ans = 0;
    while (cnt > 0) {
        sort(v.begin(), v.end(), cmp);
        visited[v[0].first] = true;
        ans = max(ans, v[0].second);
        cnt--;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                v.push_back(make_pair(i, a[v[0].first][i]));
            }
        }
        v.erase(v.begin());
    }
    cout << ans << endl;
}