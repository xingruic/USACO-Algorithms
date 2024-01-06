#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int n, k;
typedef struct node {
    vector<node *> nodes;
    int idx;
    node(int i) :idx(i) {}
} *link;
link links[10001];
int bessie_distance[10001];
int nearest_station[10001];
bool done[10001];
int main() {
    memset(bessie_distance, 0, sizeof(bessie_distance));
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);
    for (int i = 1; i <= 10000; i++) links[i] = new node(i);
    cin >> n >> k;
    int x, y;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        links[x]->nodes.push_back(links[y]);
        links[y]->nodes.push_back(links[x]);
    }
    memset(done, 0, sizeof(done));
    queue<pair<link, int>> q;
    q.push(make_pair(links[k], 0));
    done[k] = 1;
    while (!q.empty()) {
        pair<link, int> t = q.front();
        q.pop();
        bessie_distance[t.first->idx] = t.second;
        t.second++;
        for (link i : t.first->nodes) {
            if (done[i->idx]) continue;
            done[i->idx] = 1;
            q.push(make_pair(i, t.second));
        }
    }
    memset(done, 0, sizeof(done));
    for (int i = 1; i <= n; i++) {
        if (links[i]->nodes.size() < 2) { // if its a leaf (exit)
            q.push(make_pair(links[i], 0));
            done[i] = 1;
        }
    }
    while (!q.empty()) {
        pair<link, int> t = q.front();
        q.pop();
        nearest_station[t.first->idx] = t.second;
        t.second++;
        for (link i : t.first->nodes) {
            if (done[i->idx]) continue;
            done[i->idx] = 1;
            q.push(make_pair(i, t.second));
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (nearest_station[i] - bessie_distance[i] == 1) { // if bessie can get to node i precisely 1 step before any farmer can
            // then every subtree of node i must have a farmer
            cnt += links[i]->nodes.size() - 1; // minus 1, because one of the nodes is the parent
        }
    }
    cout << cnt << endl;
}