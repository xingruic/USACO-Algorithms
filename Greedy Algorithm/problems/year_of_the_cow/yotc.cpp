#include <bits/stdc++.h>
using namespace std;
int n, k;
int yago[0x10000]; // how many Years AGO is ancestor i
struct gap {
    int l, g, size; // size is inclusive
    gap(int l, int g, int size) : l(l), g(g), size(size) {}
};
vector<pair<int, int>> splits;
vector<gap> gaps;
// void erase(int l, int r) { // cuts out the part from l to r inclusive in splits
//     for (auto split = splits.begin(); split != splits.end(); split++) {
//         if (split->first <= l && split->second >= r) {
//             if (split->second > r)
//                 splits.insert(split + 1, make_pair(r + 1, split->second));
//             if (split->first < l)
//                 splits.insert(split, make_pair(split->first, l - 1));
//             splits.erase(split + 1);
//             return;
//         }
//     }
//     throw runtime_error("the range [l,r] isn't within any existing split");
// }
inline int l12(int year) { // first multiple of 12 thats less
    return floor(year / 12.0) * 12;
}
inline int g12(int year) { // first multiple of 12 thats greater
    return ceil(year / 12.0) * 12;
}
int main() {
    memset(yago, -1, sizeof(yago));
    cin >> n >> k;
    k--;
    for (int i = 0; i < n; i++) {
        cin >> yago[i];
    }
    sort(yago, yago + n);
    splits.push_back(make_pair(0, g12(yago[n - 1])));
    if (l12(yago[0]) != 0)
        gaps.push_back(gap(0, l12(yago[0]), l12(yago[0])));
    for (int i = 0; i < n - 1; i++) {
        int l = l12(yago[i + 1]), g = g12(yago[i]);
        if (l > g) {
            gaps.push_back(gap(g, l, l - g));
        }
    }
    sort(gaps.begin(), gaps.end(), [](gap &l, gap &r) { return l.size > r.size; });
    int ans = splits[0].second;
    // cout << ans << endl;
    for (int i = 0; i < gaps.size() && i < k; i++) {
        ans -= gaps[i].size;
        // cout << gaps[i].l << ' ' << gaps[i].g << ' ' << gaps[i].size << endl;
    }
    cout << ans << endl;
}