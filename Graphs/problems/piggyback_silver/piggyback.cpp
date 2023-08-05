#include<bits/stdc++.h>
using namespace std;
int b, e, p, n, m;
int bd[40001], ed[40001], fd[40001];
vector<int> road[40001];
bool visited[40001];
queue<int> q;
int main() {
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);
    memset(bd, 0x3d, sizeof(bd));
    memset(ed, 0x3d, sizeof(ed));
    memset(fd, 0x3d, sizeof(fd));
    cin >> b >> e >> p >> n >> m;
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        road[x].push_back(y);
        road[y].push_back(x);
    }
    memset(visited, 0, sizeof(visited));
    q.push(1);
    bd[1] = 0;
    visited[1] = 1;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int &next : road[t]) {
            if (visited[next]) continue;
            visited[next] = 1;
            bd[next] = bd[t] + b;
            q.push(next);
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << bd[i] << ' ';
    // } cout<<endl;
    memset(visited, 0, sizeof(visited));
    q.push(2);
    ed[2] = 0;
    visited[2] = 1;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int &next : road[t]) {
            if (visited[next]) continue;
            visited[next] = 1;
            ed[next] = ed[t] + e;
            q.push(next);
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << ed[i] << ' ';
    // } cout<<endl;
    memset(visited, 0, sizeof(visited));
    q.push(n);
    fd[n] = 0;
    visited[n] = 1;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int &next : road[t]) {
            if (visited[next]) continue;
            visited[next] = 1;
            fd[next] = fd[t] + p;
            q.push(next);
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << fd[i] << ' ';
    // } cout << endl;
    int mindist = bd[n] + ed[n];
    for (int i = 1; i <= n;i++) {
        if (bd[i] + ed[i] + fd[i] < mindist) {
            mindist = bd[i] + ed[i] + fd[i];
        }
    }
    cout << mindist << endl;
}