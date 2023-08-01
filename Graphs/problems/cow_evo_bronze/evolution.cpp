#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> traits[25];
map<string, int> order;
int main() {
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);
    cin >> n;
    int k;
    // vector<int> tmp;
    for (int i = 0; i < n; i++) {
        cin >> k;
        traits[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> traits[i][j];
        }
    }
    sort(traits, traits + n, [](vector<string> &a, vector<string> &b) {return a.size() < b.size();});
    for (int i = 0; i < n; i++) {
        for (string &j : traits[i]) {
            if (order.count(j) == 0) order[j] = order.size();
        }
    }
    for (int i = 0; i < n; i++) {
        sort(traits[i].begin(), traits[i].end(), [](string &a, string &b) {return order[a] < order[b];});
    }
    // for (int i = 0; i < n; i++) {
    //     for (string &j : traits[i]) cout << j << ' ';
    //     cout << endl;
    // }
    for (auto &j : order) j.second = -1;
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < traits[i].size(); j++) {
            if (order[traits[i][j]] >= 0) {
                if (j != order[traits[i][j]]) {
                    cout << "no" << endl;
                    return 0;
                }
            } else {
                order[traits[i][j]] = j;
            }
        }
    }
    cout << "yes" << endl;
}