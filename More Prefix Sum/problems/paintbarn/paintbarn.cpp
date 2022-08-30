#include <fstream>
#include <iostream>
#include <memory.h>
using namespace std;

// input
int n, k;
int a[201][201];

// these are all prefix subsets
int sum[201][201];
unsigned short numinc[201][201]; // number of squares that could be made equal to k by an increment
unsigned short numk[201][201]; // number of squares that are equal to k

// int inline subseq(int x1, int y1, int x2, int y2) {
//     return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1][y1];
// }
// int inline nisubseq(int x1, int y1, int x2, int y2) {
//     return numinc[x2][y2] - numinc[x1 - 1][y2] - numinc[x2][y1 - 1] + numinc[x1][y1];
// }
// int inline ksubseq(int x1, int y1, int x2, int y2) {
//     return numk[x2][y2] - numk[x1 - 1][y2] - numk[x2][y1 - 1] + numk[x1][y1];
// }
// int inline nikdiff(int x1, int y1, int x2, int y2) {
//     return nisubseq(x1, y1, x2, y2) - ksubseq(x1, y1, x2, y2);
// }

int main() {
    int t = clock();
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    memset(a, 0, sizeof(a));
    memset(numinc, 0, sizeof(numinc));
    memset(numk, 0, sizeof(numk));
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int k = x1; k <= x2; k++) {
            for (int l = y1; l <= y2; l++) {
                a[k][l]++;
            }
        }
    }
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++)
            cerr << a[i][j] << ' ';
        cerr << endl;
    }
    for (int i = 1; i <= 200; i++) {
        for (int j = 1; j <= 200; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
            numinc[i][j] = numinc[i - 1][j] + numinc[i][j - 1] - numinc[i - 1][j - 1] + (int)(a[i][j] == k - 1);
            numk[i][j] = numk[i - 1][j] + numk[i][j - 1] - numk[i - 1][j - 1] + (int)(a[i][j] == k);
        }
    }
    cerr << (clock() - t) * 1.0 / CLOCKS_PER_SEC << endl;
    t = clock();
    int ans = numk[200][200];

    int p1 = -1, q1 = -1, p2 = -1, q2 = -1, maxnikd = 0;
    for (int x1 = 1; x1 <= 200; x1++) {
        for (int y1 = 1; y1 <= 200; y1++) {
            for (int x2 = x1; x2 <= 200; x2++) {
                for (int y2 = y1; y2 <= 200; y2++) {
                    int val = (numinc[x2][y2] - numinc[x1 - 1][y2] - numinc[x2][y1 - 1] + numinc[x1][y1]) - (numk[x2][y2] - numk[x1 - 1][y2] - numk[x2][y1 - 1] + numk[x1][y1]);
                    if (val > maxnikd) {
                        maxnikd = val;
                        p1 = x1, q1 = y1, p2 = x2, q2 = y2;
                    }
                }
            }
        }
    }
    cerr << p1 << ' ' << q1 << ' ' << p2 << ' ' << q2 << ' ' << maxnikd << endl;
    ans += maxnikd;
    int P1 = p1, Q1 = q1, P2 = p2, Q2 = q2;
    cerr << (clock() - t) * 1.0 / CLOCKS_PER_SEC << endl;
    t = clock();

    p1 = -1, q1 = -1, p2 = -1, q2 = -1, maxnikd = 0;
    for (int x1 = 1; x1 <= 200; x1++) {
        for (int y1 = 1; y1 <= 200; y1++) {
            for (int x2 = x1; x2 <= 200; x2++) {
                for (int y2 = y1; y2 <= 200; y2++) {
                    if (
                        x1 > P1 && x1 < P2 && y1 > Q1 && y1 < Q2 ||
                        x2 > P1 && x2 < P2 && y2 > Q1 && y2 < Q2) {
                        continue;
                    }
                    int val = (numinc[x2][y2] - numinc[x1 - 1][y2] - numinc[x2][y1 - 1] + numinc[x1][y1]) - (numk[x2][y2] - numk[x1 - 1][y2] - numk[x2][y1 - 1] + numk[x1][y1]);
                    if (val > maxnikd) {
                        maxnikd = val;
                        p1 = x1, q1 = y1, p2 = x2, q2 = y2;
                    }
                }
            }
        }
    }
    cerr << p1 << ' ' << q1 << ' ' << p2 << ' ' << q2 << ' ' << maxnikd << endl;
    ans += maxnikd;
    cerr << (clock() - t) * 1.0 / CLOCKS_PER_SEC << endl;

    cout << ans << endl;
}