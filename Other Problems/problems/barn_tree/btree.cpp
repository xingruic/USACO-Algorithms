#include <bits/stdc++.h>
using namespace std;
int n;
int h[200001];
pair<int, int> edges[200000];
int avg = 0;
int numEdges[200001];
struct mov {
    int start, end, x;
    mov(int s, int e, int v) {
        start = s, end = e, x = v;
    }
};
int main() {
    // memset(a, 0x3c, sizeof(a));
    memset(numEdges, 0, sizeof(numEdges));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        avg += h[i];
    }
    avg /= n;
    for (int i = 1; i < n; i++) {
        cin >> edges[i].first >> edges[i].second;
        numEdges[edges[i].first]++, numEdges[edges[i].second]++;
    }
    int cnt = 0;
    vector<mov> moves;
    for (int i = 1; i < n; i++) {
        cnt++;
        if (numEdges[edges[i].first] == 1 && h[edges[i].first] < avg) {
            h[edges[i].first] += min(edges[i].second, avg - edges[i].first);
            h[edges[i].second] = max(h[edges[i].second] - avg, 0);
            moves.push_back(mov(edges[i].second, edges[i].first, min(edges[i].second, avg - edges[i].first)));
        } else if (numEdges[edges[i].second] == 1 && h[edges[i].second] < avg) {
            h[edges[i].second] += min(edges[i].first, avg - edges[i].second);
            h[edges[i].first] = max(h[edges[i].first] - avg, 0);
            moves.push_back(mov(edges[i].first, edges[i].second, min(edges[i].first, avg - edges[i].second)));
        } else
            cnt--;
    }
    for (int i = 1; i < n; i++) {
        cnt++;
        if (h[edges[i].first] < avg) {
            h[edges[i].first] += min(edges[i].second, avg - edges[i].first);
            h[edges[i].second] = max(h[edges[i].second] - avg, 0);
            moves.push_back(mov(edges[i].second, edges[i].first, min(edges[i].second, avg - edges[i].first)));
        } else if (h[edges[i].second] < avg) {
            h[edges[i].second] += min(edges[i].first, avg - edges[i].second);
            h[edges[i].first] = max(h[edges[i].first] - avg, 0);
            moves.push_back(mov(edges[i].first, edges[i].second, min(edges[i].first, avg - edges[i].second)));
        } else
            cnt--;
    }
    cout << cnt << endl;
    for (mov i : moves) {
        cout << i.start << ' ' << i.end << ' ' << i.x << endl;
    }
}