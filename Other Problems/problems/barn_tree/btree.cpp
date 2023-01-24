#include <bits/stdc++.h>
using namespace std;
int n;
int h[200001];
pair<int, int> Edges[200000];
int avg = 0;
struct Node {
    int idx;
    int x;
    vector<Node *> v;
};
typedef Node *node;
node nodes[200001];
bool good[200001] = {0};
struct step {
    int i, j, x;
    step(int ii, int jj, int xx) : i(ii), j(jj), x(xx) {}
};
vector<step> steps;
void solve(node x, node parent) {
    // cout << x->idx << endl;
    if (good[x->idx]) {
        return;
    }
    good[x->idx] = 1;
    for (int i = 0; i < x->v.size(); i++) {
        if (x->x == 0)
            break;
        if (x->v[i]->x < avg) {
            int trans = min(avg - x->v[i]->x, x->x);
            x->v[i]->x += trans;
            x->x -= trans;
            steps.push_back(step(x->idx, x->v[i]->idx, trans));
        }
        solve(x->v[i], x);
    }
    if (x->x > avg && parent) {

        for (int i = 0; i < steps.size(); i++) {
            // cout << i << ' ';
            if (steps[i].i == parent->idx && steps[i].j == x->idx) {
                steps[i].x -= x->x - avg;
            }
        }
        cout << endl;
    }
}
int main() {
    // memset(a, 0x3c, sizeof(a));
    cin >> n;
    for (int i = 0; i <= n; i++) {
        nodes[i] = (node)malloc(sizeof(Node));
    }
    int root_idx;
    {
        int max_val = -1;
        for (int i = 1; i <= n; i++) {
            cin >> h[i];
            // h[i] = 1;
            if (h[i] > max_val) {
                max_val = h[i];
                root_idx = i;
            }
            avg += h[i];
            nodes[i]->idx = i;
            nodes[i]->x = h[i];
        }
    }
    avg /= n;
    for (int i = 1; i < n; i++) {
        cin >> Edges[i].first >> Edges[i].second;
        nodes[Edges[i].first]->v.push_back(nodes[Edges[i].second]);
        nodes[Edges[i].second]->v.push_back(nodes[Edges[i].first]);
    }
    // cout << "what" << endl;
    solve(nodes[root_idx], nullptr);
    for (int i = 1; i <= n; i++) {
        cout << nodes[i]->idx << ' ' << nodes[i]->x << endl;
    }
    cout << steps.size() << endl;
    for (step i : steps) {
        cout << i.i << ' ' << i.j << ' ' << i.x << endl;
    }
}