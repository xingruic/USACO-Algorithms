#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int maxn = 2e5;
string s;
vector<pair<int, int>> query;
int csum[maxn + 1], osum[maxn + 1], wsum[maxn + 1];
char calc(int a, int b) {
    int o = osum[b] - osum[a - 1],
        w = wsum[b] - wsum[a - 1],
        c = csum[b] - csum[a - 1];
    // for (int i = c;i--;) cout << 'C';
    // for (int i = o;i--;) cout << 'O';
    // for (int i = w;i--;) cout << 'W';
    // cout << endl;
    if (o % 2 && w % 2) {
        if (c % 2)return 'N';
        return 'Y';
    }
    if (!(o % 2 || w % 2)) {
        if (c % 2) return 'Y';
    }
    return 'N';
}
int main() {
    // freopen("cowop.in", "r", stdin);
    // freopen("cowop.out", "w", stdout);
    cin >> s;
    {
        int a, b;
        cin >> a;
        for (int i = a; i--;) {
            cin >> a >> b;
            query.push_back(make_pair(a, b));
        }
        csum[0] = osum[0] = wsum[0] = 0;
        for (int i = 1; i <= s.size(); i++) {
            csum[i] = csum[i - 1];
            osum[i] = osum[i - 1];
            wsum[i] = wsum[i - 1];
            csum[i] += (s[i - 1] == 'C');
            osum[i] += (s[i - 1] == 'O');
            wsum[i] += (s[i - 1] == 'W');
        }
        // for (int i = 1; i <= s.size(); i++) {
        //     cout << csum[i] << ' ' << osum[i] << ' ' << wsum[i] << endl;
        // }
    }
    for (pair<int, int> &i : query) {
        cout << calc(i.first, i.second);
    }cout << endl;
}