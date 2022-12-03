#include <bits/stdc++.h>
using namespace std;
string cross;
int enter['Z' + 1], out['Z' + 1];
bool counted['Z' + 1]['Z' + 1];
bool crosses(int i, int j) {
    if (enter[j] > enter[i] && enter[j] < out[i]) {
        if (out[j] < enter[i] || out[j] > out[i])
            return 1;
    }
    if (out[j] > enter[i] && out[j] < out[i]) {
        if (enter[j] < enter[i] || enter[j] > out[i])
            return 1;
    }
    return 0;
}
int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    memset(counted, 0, sizeof(counted));
    memset(enter, -1, sizeof(enter));
    memset(out, -1, sizeof(out));
    cin >> cross;
    for (int i = 0; i < cross.size(); i++) {
        if (enter[cross[i]] == -1)
            enter[cross[i]] = i;
        else
            out[cross[i]] = i;
    }
    // cout << enter['A'] << ' ' << out['A'] << ' ' << enter['B'] << ' ' << out['B'] << endl;
    int cnt = 0;
    for (int i = 'A'; i <= 'Z'; i++) {
        for (int j = i + 1; j <= 'Z'; j++) {
            if (crosses(i, j)) {
                // cout << (char)i << ' ' << (char)j << endl;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}