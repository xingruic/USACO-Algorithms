#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> a;
bool cmp(pair<int, int> x, pair<int, int> y) {
    return x.second < y.second;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back(make_pair(x, y));
    }
    sort(a.begin(), a.end(), cmp);
    bool done = 0;
    vector<int> ans;
    int finish = -1;
    int x = 0;
    while (!done) {
        done = 1;
        for (int i = x; i < n; i++) {
            if (a[i].first >= finish) {
                done = 0;
                finish = a[i].second;
                ans.push_back(i);
                x = i + 1;
            }
        }
    }
    cout << ans.size() << endl;
}