#include <bits/stdc++.h>
using namespace std;
string s, t;
int _hash(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
        sum += i * s[i];
    return sum % 1000000007;
}
vector<int> rk(string large, string find) {
    // cout << large << ' ' << find << endl;
    int hashf = _hash(find);
    int n = large.size() - find.size() + 1;
    int hashl[n];
    string t[n];
    memset(hashl, 0, sizeof(hashl) / sizeof(int));
    for (int i = 0; i < n; i++) {
        t[i] = "";
        for (int j = i; j < i + find.size(); j++) {
            t[i] += large[j];
        }
        hashl[i] = _hash(t[i]);
    }
    vector<int> locations;
    for (int i = 0; i < n; i++) {
        // cout << hashf << ' ' << hashl[i] << endl;
        if (hashl[i] == hashf) {
            if (t[i] == find) {
                locations.push_back(i);
            }
        }
    }
    return locations;
}
int main() {
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    cin >> s >> t;
    vector<int> locs = {0};
    while (locs.size() > 0) {
        locs = rk(s, t);
        for (int &i : locs) {
            // cout << i << endl;
            s.erase(i, t.size());
        }
    }
    cout << s << endl;
}