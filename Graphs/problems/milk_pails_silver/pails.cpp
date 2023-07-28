#include<bits/stdc++.h>
using namespace std;
int X, Y, K, M;
struct step {
    int x, y, k;
    step(int x, int y, int k) :x(x), y(y), k(k) {}
};
inline int toi(const step &s) {
    return (((s.x << 7) + s.y) << 7) + s.k; // 7 because 100 is 7 digits long in binary
}
queue<step> q;
unordered_set<int> done;
int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    cin >> X >> Y >> K >> M;
    q.push(step(0, 0, 0));
    int closest = 0x7fffffff;
    while (!q.empty()) {
        step s = q.front();
        q.pop();
        if (done.count(toi(s)) > 0) {
            continue;
        }
        done.insert(toi(s));
        closest = min(closest, abs(M - s.x - s.y));
        if (s.k == K) {
            continue;
        }
        s.k++;
        q.push(step(0, s.y, s.k));
        q.push(step(s.x, 0, s.k));
        q.push(step(X, s.y, s.k));
        q.push(step(s.x, Y, s.k));
        if (X - s.x >= s.y) {
            q.push(step(s.x + s.y, 0, s.k));
        } else {
            q.push(step(X, s.y - (X - s.x), s.k));
        }
        if (Y - s.y >= s.x) {
            q.push(step(0, s.x + s.y, s.k));
        } else {
            q.push(step(s.x - (Y - s.y), 0, s.k));
        }
    }
    cout << closest << endl;
}