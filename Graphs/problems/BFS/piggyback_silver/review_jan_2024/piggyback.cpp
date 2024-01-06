#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
// i basically copied this from the official solution btw
vector<long long> D(long long st, const vector<vector<long long>> &E) {
    vector<long long> D(E.size(), -1);

    deque<long long> Q;
    D[st] = 0;
    Q.push_back(st);
    while (!Q.empty()) {
        long long x = Q.front(); Q.pop_front();
        for (long long y : E[x]) {
            if (D[y] == -1) {
                D[y] = D[x] + 1;
                Q.push_back(y);
            }
        }
    }
    return D;
}
int main() {
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);
    long long b, e, p, n, m;
    cin >> b >> e >> p >> n >> m;
    vector<vector<long long>> E(n, vector<long long>());
    for (long long i = 0; i < m; i++) {
        long long x, y;
        cin >> x >> y;
        x--, y--;
        E[x].push_back(y);
        E[y].push_back(x);
    }

    vector<long long>
        D0 = D(0, E),
        D1 = D(1, E),
        Dn = D(n - 1, E);

    long long ans = (long long)1000 * 1000 * 1000 * 1000;
    for (long long meet = 0; meet < n; meet++) {
        ans = min(ans, D0[meet] * b + D1[meet] * e + Dn[meet] * p);
    }
    cout << ans << endl;
}