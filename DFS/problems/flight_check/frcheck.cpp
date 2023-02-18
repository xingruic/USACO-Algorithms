#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n, m;
vector<int> a[100001];
set<int> to[100001];
bool done[100001];
void dfs(int x) {
    if (done[x])
        return;
    done[x] = 1;
    to[x].insert(x);
    for (int i : a[x]) {
        to[x].insert(i);
        dfs(i);
        for (int j : to[i]) {
            // if (i == 1)
            //     cout << j << ' ';
            to[x].insert(j);
        }
        // if (i == 1)
        //     cout << endl;
    }
}
int main() {
    memset(done, 0, sizeof(done));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        dfs(i);
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j : to[i]) {
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (to[i].find(j) == to[i].end()) {
                cout << "NO\n"
                     << i << ' ' << j << '\n';
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}