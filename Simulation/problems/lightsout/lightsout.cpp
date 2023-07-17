#include <bits/stdc++.h>
using namespace std;
int n;
int x[202], y[202], start[201], stop[201], distprev[201];
char dir[201];
string barn = "";
inline int shortest(int &v) {
    int ans = 0, ans2 = 0;
    for (int i = v; i > 1; i--) {
        ans += distprev[i];
    }
    for (int i = v + 1; i <= n + 1; i++) {
        ans2 += distprev[i];
    }
    return min(ans, ans2);
}
inline bool uniq(const string &dbarn) {
    int pos = 0, cnt = 0;
    while ((pos = barn.find(dbarn, pos)) != string::npos) {
        // cout << pos << endl;
        cnt++;
        pos++;
    }
    return cnt == 1;
}
int main() {
    freopen("lightsout.in", "r", stdin);
    freopen("lightsout.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n + 1; i++) {
        if (i <= n)
            cin >> x[i] >> y[i];
        if (i > 1) {
            if (x[i] == x[i - 1])
                dir[i] = y[i] > y[i - 1] ? 'n' : 's';
            else
                dir[i] = x[i] > x[i - 1] ? 'e' : 'w';
            // cout << dir[i] << endl;
        } else
            x[n + 1] = x[1], y[n + 1] = y[1];
    }
    if (x[1] == x[2]) {
        barn += to_string(distprev[2] = abs(y[2] - y[1]));
    } else {
        barn += to_string(distprev[2] = abs(x[2] - x[1]));
    }
    for (int i = 2; i <= n; i++) {
        start[i] = barn.size();
        if (dir[i] == 'n') {
            if (dir[i + 1] == 'e')
                barn += 'r';
            else
                barn += 'l';
        } else if (dir[i] == 'e') {
            if (dir[i + 1] == 's')
                barn += 'r';
            else
                barn += 'l';
        } else if (dir[i] == 'w') {
            if (dir[i + 1] == 'n')
                barn += 'r';
            else
                barn += 'l';
        } else {
            if (dir[i + 1] == 'w')
                barn += 'r';
            else
                barn += 'l';
        }
        if (dir[i + 1] == 'n' || dir[i + 1] == 's') {
            distprev[i + 1] = abs(y[i + 1] - y[i]);
            // cout << "ns " << y[i + 1] << ' ' << y[i] << endl;
            barn += to_string(distprev[i + 1]);
        } else {
            distprev[i + 1] = abs(x[i + 1] - x[i]);
            barn += to_string(distprev[i + 1]);
            // cout << "ew " << x[i + 1] << ' ' << x[i] << endl;
        }
        // cout << distprev[i + 1] << endl;
        stop[i] = barn.size();
    }
    distprev[1] = distprev[n + 1];
    cout << barn << endl;
    int maxl = 0;
    // for (int i = 1; i <= n; i++)
    //     cout << shortest(i) << ' ';
    // cout << endl;
    for (int i = 2; i <= n; i++) {
        int norm = shortest(i);
        int j;
        int dist = 0;
        for (j = i + 1; j <= n; j++) {
            dist += distprev[j];
            if (uniq(barn.substr(start[i], stop[j]))) {
                break;
            }
        }
        if (j > n) {
            maxl = max(maxl, dist - norm);
        } else {
            maxl = max(maxl, dist + shortest(j) - norm);
            // cout << "# ";
        }
        // cout << i << ' ' << j << ' ' << barn.substr(start[i], stop[j]) << ' ' << dist << ' ' << shortest(j) << ' ' << norm << endl;
    }
    cout << maxl << endl;
}