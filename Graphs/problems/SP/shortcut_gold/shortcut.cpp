#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int maxn = 1e4;
int n, m, T;
int reduction[maxn + 1];
int c[maxn + 1];
struct edge {
    int a, b, l;
    edge(int a, int b, int l) :a(a), b(b), l(l) {}
};
vector<edge *> edges;
int main() {
    fill(reduction, reduction + maxn + 1, -1);
    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);
    cin >> n >> m >> T;
    for (int i = 1; i <= n; i++) cin >> c[i];
    edges.resize(m);
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        edges[i] = new edge(a, b, t);
    }
    sort(edges.begin(), edges.end(), [](edge *a, edge *b) {return (a->l) < (b->l);});
    for (edge *i : edges) {
        cout << (i->a) << ' ' << (i->b) << ' ' << (i->l) << endl;
    }
    for (int cnt = 0; cnt < n;) {
        for (int i = 0; i < edges.size(); i++) {
            if (reduction[edges[i]->a] >= 0) {
                if (reduction[edges[i]->b] >= 0) continue;
                else {
                    reduction[edges[i]->b] = reduction[edges[i]->a] + edges[i]->l;
                    cnt++;
                    break;
                }
            } else if (reduction[edges[i]->b] >= 0) {
                reduction[edges[i]->a] = reduction[edges[i]->b] + edges[i]->l;
                cnt++;
                break;
            }
        }
    }

}