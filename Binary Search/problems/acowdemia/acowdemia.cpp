#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
int N, K, L;
int c[100000];
int binsearch(int l, int r) {
    if (l == r) return l;
    int m = (l + r) / 2 + 1;
    int h = m;
    int i;
    for (i = N - 1; i >= 0 && c[i] >= m; i--, h--);
    if (h <= 0) {
        return binsearch(m, r);
    }
    int total_cost = 0;
    int cost;
    while (h > 0) {
        cost = m - c[i];
        if (cost > K) return binsearch(l, m - 1);
        total_cost += cost;
        h--;
        i--;
    }
    if (total_cost > K * L) {
        return binsearch(l, m - 1);
    }
    return binsearch(m, r);
}
int main() {
    // freopen("acowdemia.in", "r", stdin);
    // freopen("acowdemia.out", "w", stdout);
    cin >> N >> K >> L;
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }
    sort(c, c + N);
    cout << binsearch(1, N) << endl;
}