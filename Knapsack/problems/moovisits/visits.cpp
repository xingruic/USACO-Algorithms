#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
int n;
struct cow {
    int a, v, net, group = -1;
    cow(int a, int v, int net, int group) : a(a), v(v), net(net), group(group) {}
    cow() {
        cow(-1, -1, -1, -1);
    }
} cows[100001];
void groupit(int idx, int gid) {
    if (cows[idx].group != -1)
        return;
    cows[idx].group = gid;
    groupit(cows[idx].a, gid);
}
int main() {
    freopen("visits.in", "r", stdin);
    freopen("visits.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cows[i].a >> cows[i].v;
    }
    for (int i = 1; i <= n; i++) {
        cows[cows[i].a].net = cows[cows[i].a].v - cows[i].v;
    }
    for (int i = 1; i <= n; i++) {
        groupit(i, i);
    }
    sort(cows + 1, cows + 1 + n, [](cow l, cow r) { return l.group < r.group; });
    for (int i = 1; i <= n; i++) {
        cout << cows[i].group << endl;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int minnet = 0x7fffffff, idx = -1;
        for (; (i == 1 || cows[i].group == cows[i - 1].group) && i <= n; i++) {
            if (minnet > cows[i].net)
                minnet = cows[i].net, idx = i;
        }
        ans -= cows[idx].v;
        cout << idx << ' ' << cows[idx].a << ' ' << cows[idx].v << ' ' << cows[idx].net << ' ' << cows[idx].group << endl;
    }
    for (int i = 1; i <= n; i++)
        ans += cows[i].v;
    cout << ans << endl;
}