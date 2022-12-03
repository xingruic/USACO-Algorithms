#include <iostream>
// #include <algorithm>
#include <map>
using namespace std;
map<string, int> prop_cnt; // number of animals with this property
int main() {
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    {
        int n;
        cin >> n;
        string s;
        int x;
        for (int i = 1; i <= n; i++) {
            cin >> s;
            cin >> x;
            for (int j = 1; j <= x; j++) {
                cin >> s; // dont worry about s, we dont need the animal name
                if (prop_cnt.find(s) != prop_cnt.end()) {
                    prop_cnt[s]++;
                } else {
                    prop_cnt[s] = 1;
                }
            }
        }
    }
    int cnt = 0;
    for (pair<string, int> i : prop_cnt) {
        // cout << i.second << endl;
        if (i.second > 1)
            cnt++;
    }
    cout << cnt + 1 << endl;
}