#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int N;
short g[501][501];
short hsum[502][502], vsum[502][502];
vector<pair<short, short> > hund; // g[i][j] = 100
int main() {
    memset(hsum, 0, sizeof(hsum));
    memset(vsum, 0, sizeof(vsum));
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> g[i][j];
            if (g[i][j] < 100) {
                hsum[i][j]++;
                hsum[i][j + 1] = hsum[i][j] + 1;
                vsum[i][j]++;
                vsum[i + 1][j] = vsum[i][j] + 1;
            } else {
                if (g[i][j] == 100) {
                    hund.push_back(make_pair(i, j));
                }
                hsum[i][j + 1] = hsum[i][j];
                vsum[i + 1][j] = vsum[i][j];
            }
        }
    }
    // cout << "hsum ============" << endl;
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << hsum[i][j] << ' ';
    //     }cout << endl;
    // }
    // cout << "vsum ============" << endl;
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << vsum[i][j] << ' ';
    //     }cout << endl;
    // }

    // make it so that when you go upward or leftward, it exits on <= 100
    // and when downward or rightward, it exits on < 100
    // this way it counts the ones with multiple 100s only once

    short p, q, hs, vs, ub, db, lb, rb;
    for (const pair<short, short> &h : hund) {
        p = h.first, q = h.second; // p and q --> i and j
        hs = hsum[p][q], vs = vsum[p][q]; // hsum and vsum at the 100 at point h
        ub = 1, db = N, lb = 1, rb = N; // up,down,left,right bounds (inclusive)
        short low = p, m = 0;
        while (low != ub) {
            m = (low + ub) / 2;
            if (vsum[m][q] != vs) {
                ub = m + 1;
            } else {
                low = m;
            }
        }
        low = p;
        while (low != db) {
            m = (low + db) / 2 + 1;
            if (vsum[m][q] != vs) {
                db = m - 1;
            } else {
                low = m;
            }
        }
        low = q;
        while (low != lb) {
            m = (low + lb) / 2;
            if (hsum[p][m] != hs) {
                lb = m + 1;
            } else {
                low = m;
            }
        }
        low = p;
        while (low != rb) {
            m = (low + rb) / 2 + 1;
            if (hsum[p][m] != hs) {
                rb = m - 1;
            } else {
                low = m;
            }
        }
        // cout << ub << ' ' << db << ' ' << lb << ' ' << rb << endl;

    }
}