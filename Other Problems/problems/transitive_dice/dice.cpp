#include <bits/stdc++.h>
using namespace std;
int t;
int a[4], b[4], c[4];
bool check(bool a_b) { // a_b is whether a>b
    if (a_b) {
        int cnta = 0, cntb = 0, cntc = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (b[i] > c[j])
                    cntb++;
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (c[i] > b[j])
                    cntc++;
            }
        }
        if (cntb < cntc)
            return 0;
        cntc = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (a[i] > c[j])
                    cnta++;
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (c[i] > a[j])
                    cntc++;
            }
        }
        if (cnta > cntc)
            return 0;
    } else {
        int cnta = 0, cntb = 0, cntc = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (b[i] > c[j])
                    cntb++;
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (c[i] > b[j])
                    cntc++;
            }
        }
        if (cntb > cntc)
            return 0;
        cntc = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (a[i] > c[j])
                    cnta++;
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (c[i] > a[j])
                    cntc++;
            }
        }
        if (cnta < cntc)
            return 0;
    }
    return 1;
}
int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a[i];
        }
        for (int j = 0; j < 4; j++) {
            cin >> b[i];
        }
        int acnt = 0, bcnt = 0;
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (a[j] > b[k]) {
                    acnt++;
                }
            }
        }
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (a[j] < b[k]) {
                    bcnt++;
                }
            }
        }
        bool f = 0;
        for (c[0] = 1; c[0] <= 10; c[0]++) {
            for (c[1] = 1; c[1] <= 10; c[1]++) {
                for (c[2] = 1; c[2] <= 10; c[2]++) {
                    for (c[3] = 1; c[3] <= 10; c[3]++) {
                        if (check(acnt > bcnt)) {
                            cout << "yes" << endl;
                            f = 1;
                            break;
                        }
                    }
                    if (f)
                        break;
                }
                if (f)
                    break;
            }
            if (f)
                break;
        }
        if (!f)
            cout << "no" << endl;
    }
}