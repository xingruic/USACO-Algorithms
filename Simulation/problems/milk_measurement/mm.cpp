#include <bits/stdc++.h>
using namespace std;
struct entry {
    int net = 0;
    string name = "x";
} entries[101];
short b[101], e[101], m[101];
int n;
int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    cin >> n;
    int d;
    string net;
    for (int i = 0; i < n; i++) {
        cin >> d;
        cin >> entries[d].name >> net;
        entries[d].net = (net[0] == '-' ? (-atoi(net.substr(1).c_str())) : (atoi(net.substr(1).c_str())));
    }
    b[0] = e[0] = m[0] = 7;
    for (int i = 1; i <= 100; i++) {
        b[i] = b[i - 1];
        e[i] = e[i - 1];
        m[i] = m[i - 1];
        switch (entries[i].name[0]) {
        case 'B':
            b[i] += entries[i].net;
            break;
        case 'E':
            e[i] += entries[i].net;
            break;
        case 'M':
            m[i] += entries[i].net;
            break;
        }
    }
    bool bb = 1, be = 1, bm = 1, bc = 0;
    int cnt = 0;
    for (int i = 1; i <= 100; i++, bc = 0) {
        if ((b[i] < e[i]) + (b[i] < m[i])) {
            if (bb)
                bc = 1;
            bb = 0;
        } else {
            if (!bb)
                bc = 1;
            bb = 1;
        }
        if ((e[i] < b[i]) + (e[i] < m[i])) {
            if (be)
                bc = 1;
            be = 0;
        } else {
            if (!be)
                bc = 1;
            be = 1;
        }
        if ((m[i] < b[i]) + (m[i] < e[i])) {
            if (bm)
                bc = 1;
            bm = 0;
        } else {
            if (!bm)
                bc = 1;
            bm = 1;
        }
        if (bc) {
            // cout << i << endl;
            // cout << b[i] << ' ' << e[i] << ' ' << m[i] << endl;
            cnt++;
        }
    }
    cout << cnt << endl;
}