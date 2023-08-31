#include <bits/stdc++.h>
using namespace std;
bool visited[20001];
struct node {
    int idx;
    vector<node *> neigh;
    node(int idx) : idx(idx) {}
};
vector<node> nodes;
int n;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        nodes.push_back(node(i));
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        nodes[a - 1].neigh.push_back(&nodes[b - 1]);
        nodes[b - 1].neigh.push_back(&nodes[a - 1]);
    }
    queue<pair<node *, int>> q;
    for (int i = 0; i < n; i++) {
        memset(visited, 0, sizeof(visited));
        visited[i] = 1;
        q.push(make_pair(&nodes[i], 0));
        int ans = 0;
        while (!q.empty()) {
            pair<node *, int> t = q.front();
            q.pop();
            ans = max(ans, t.second);
            for (node *n : t.first->neigh) {
                if (!visited[n->idx]) {
                    visited[n->idx] = 1;
                    q.push(make_pair(n, t.second + 1));
                }
            }
        }
        cout << ans << ' ';
    }
    cout << endl;
}