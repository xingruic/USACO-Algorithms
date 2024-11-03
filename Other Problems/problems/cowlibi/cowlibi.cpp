#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int g, n;
struct tpoint {
    int x, y, t;
}graze[100000], alibi[100000];
long long sqrdist[100000];
inline long long sqrdist(tpoint a, tpoint b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int main() {
    // freopen("cowlibi.in", "r", stdin);
    // freopen("cowlibi.out", "w", stdout);
    memset(graze, 0, sizeof(graze));
    memset(alibi, 0, sizeof(alibi));
    cin >> g >> n;
    for (int i = 0; i < g; i++) {
        cin >> graze[i].x >> graze[i].y >> graze[i].t;
    }
    for (int i = 0; i < n; i++) {
        cin >> alibi[i].x >> alibi[i].y >> alibi[i].t;
    }
    sort(graze, graze + g, [](tpoint a, tpoint b) { return a.t < b.t; });
    tpoint p1, p2;
    int cnt = 0;
    for (int cow = 0; cow < n; cow++) {
        int gz;
        if (alibi[cow].t < graze[0].t) {
            p1 = alibi[cow];
            gz = 0;
        } else {
            p1 = graze[0];
            gz = 1;
        }
        for (; gz < g; gz++) {
            if (p1.t < alibi[cow].t && alibi[cow].t < graze[gz].t) {
                p2 = alibi[cow];
                gz--;
            } else {
                p2 = graze[gz];
            }
            if (sqrdist(p1, p2) > (p2.t - p1.t) * (p2.t - p1.t)) {
                // cout << "innocent" << endl;
                cnt++;
                break;
            }
            p1 = p2;
        }
        if (gz == g) {
            // cout << "guilty" << endl;
        }
    }
    cout << cnt << endl;
}