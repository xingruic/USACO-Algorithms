#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> h, subtree_sum;
vector<vector<int>> a;
vector<tuple<int, int, ll>> orders;
int n;
ll avg = 0;
void get_subtree_sum(int node, int parent) {
    subtree_sum[node] = h[node];
    for (int i : a[node]) {
        if (i != parent) {
            get_subtree_sum(i, node);
            subtree_sum[node] += subtree_sum[i];
        }
    }
}
void make_orders(int node, int parent) {
}
int main() {
    cin >> n;
    a.resize(n);
    h.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        avg += h[i];
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[x].push_back(y), a[y].push_back(x);
    }
    subtree_sum.resize(n);
    get_subtree_sum(0, 0);
}