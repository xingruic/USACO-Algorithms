#include <bits/stdc++.h>
using namespace std;
int xx, n;
int p[200001];
map<int, int> pass; // key is where the passage starts, value is the length of the passage
int main() {
    cin >> xx >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    pass[1] = xx;
    for (int i = 1; i <= n; i++) {
        // for (auto i : pass) {
        //     cerr << i.first << ' ' << i.second << endl;
        // }
        // cerr << endl;

        auto t = pass.upper_bound(p[i]);
        t--;
        int start = (*t).first;
        if (p[i] < start + (*t).second - 1)
            pass[p[i] + 1] = (*t).second - (p[i] - start + 1);
        if (start != p[i]) {
            t->second = p[i] - start + 1;
        }

        // find the largest passage and output it
        int m = 0;
        for (auto i : pass) {
            m = max(m, i.second);
        }
        cout << m;
        if (i < n)
            cout << ' ';
        else
            cout << endl;
    }
    // for (auto i : pass) {
    //     cerr << i.first << ' ' << i.second << endl;
    // }
    // cerr << endl;
}