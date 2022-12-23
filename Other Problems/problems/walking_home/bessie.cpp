#include <bits/stdc++.h>
using namespace std;
int t;
int n, k;
bool obstacle[51][51];
struct point {
    int x, y;
    int turns;
    bool rightward; // whether the cow was going rightward
    point(int _x, int _y, int _turns = 0) {
        x = _x, y = _y, turns = _turns;
    }
};
int main() {
    cin >> t;
    freopen("bessie.out", "w", stdout);
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        char c;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                cin >> c;
                // cout << c;
                if (c == 'H')
                    obstacle[j][k] = 1;
            }
        }
        queue<point> q;
        q.push(point(1, 1));
        int cnt = 0;
        while (!q.empty()) {
            point t = q.front();
            q.pop();
            if (t.turns > k)
                continue;
            if (t.x == n && t.y == n)
                cnt++;
            if (t.x < n && !obstacle[t.x + 1][t.y]) {
                bool r = t.rightward;
                if (!r && t.x != 0 && t.y != 0) {
                    t.turns++;
                }
                t.rightward = true;
                t.x++;
                q.push(t);
                t.x--;
                t.rightward = r;
                if (!r && t.x != 0 && t.y != 0) {
                    t.turns--;
                }
            }
            if (t.y < n && !obstacle[t.x][t.y + 1]) {
                bool r = t.rightward;
                if (r && t.x != 0 && t.y != 0) {
                    t.turns++;
                }
                t.rightward = false;
                t.y++;
                q.push(t);
            }
        }
        cout << cnt << endl;
    }
}