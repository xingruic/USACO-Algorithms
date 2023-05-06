#include <bits/stdc++.h>
using namespace std;
int n;
int x[1001], y[1001];
int a[1001][1001];
bool visited[1001];
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
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    int ans = 0;
    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        if (visited[p.second])
            continue;
        visited[p.second] = true;
        ans = max(ans, p.first);
        cnt--;
        if (cnt == 0)
            break;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                pq.push({a[p.second][i], i});
            }
        }
    }
    cout << ans << endl;
}