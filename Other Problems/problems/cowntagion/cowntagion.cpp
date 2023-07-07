#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> edge[100000];
int dist[100001];
int main() {
    freopen("cowntagion.in", "r", stdin);
    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> edge[i].first >> edge[i].second;
    }
    int cnt = 0;
    int num = 1;
    while (num < n)
        num *= 2, cnt++;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = 1; i < n; i++) {
            if (edge[i].first == t) {
                if (dist[edge[i].second] == -1) {
                    q.push(edge[i].second);
                    dist[edge[i].second] = dist[t] + 1;
                }
            } else if (edge[i].second == t) {
                if (dist[edge[i].first] == -1) {
                    q.push(edge[i].first);
                    dist[edge[i].first] = dist[t] + 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cnt += dist[i];
    }
    cout << cnt << endl;
}