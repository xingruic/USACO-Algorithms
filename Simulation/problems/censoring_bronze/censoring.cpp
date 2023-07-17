#include <bits/stdc++.h>
using namespace std;
queue<int> q;
string pat, tmp;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> pat;
    cin.clear();
    cin.seekg(0);
    n = pat.size();
    int i, c;
    cin >> setw(n) >> tmp;
    for (int cnt = n;; cnt++) {
        for (i = 0; i < n; i++) {
            if (tmp[i] != pat[i]) {
                break;
            }
        }
        if (i < n) {
            c = getc(stdin);
            if (c == '\n')
                break;
            tmp = tmp.substr(1) + (char)c;
        } else {
            cout << cnt << ' ' << tmp << endl;
            break;
        }
    }
}