#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
int n, m;
vector<pair<int, int>> grass;
int sz;
int binsearch(int l, int r) {
    if (l == r) return l;
    int m = (l + r) / 2 + 1;
    int gidx = 0;
    int i = grass[gidx].first;
    int c;
    // cout << m << '\n' << i << ' ';
    for (c = 1; c < n; c++) {
        i += m;
        for (;gidx<sz && i>grass[gidx].second;gidx++);
        if (gidx == sz) break;
        i = max(i, grass[gidx].first);
        // cout << i << ' ';
    }
    // cout << endl;
    if (c < n) {
        // cant fit all cows
        return binsearch(l, m - 1);
    } else {
        // can fit all cows
        return binsearch(m, r);
    }
}
int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        grass.push_back(make_pair(a, b));
    }
    sz = grass.size();
    sort(grass.begin(), grass.end(), [](pair<int, int> a, pair<int, int> b) {return a.first < b.first;});
    // for (int i = 0; i < m; i++) {
    //     cout << grass[i].first << ' ' << grass[i].second << endl;
    // }
    cout << binsearch(0, n) << endl;
}