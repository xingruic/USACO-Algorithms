#include<bits/stdc++.h>
using namespace std;
int intert[51][51];
const int inf = 0x7fffffff;
inline bool faces(const cow &a, const cow &b) {
    if (a.dir == 'N') return b.dir == 'S';
    if (a.dir == 'S') return b.dir == 'N';
    if (a.dir == 'E') return b.dir == 'W';
    return b.dir == 'E';
}
struct cow {
    int x, y;
    char dir;
    cow(int x, int y, char dir) :x(x), y(y), dir(dir) {}
}cows[51];
int n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cows[i].dir >> cows[i].x >> cows[i].y;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (cows[i].dir == cows[j].dir) intert[i][j] = inf;
            else if (faces(cows[i], cows[j])) {
                intert[i][j] = abs(cows[i].x - cows[j].x + cows[i].y - cows[j].y) / 2 + 1;
            } else switch (cows[i].dir) {
            case 'N':
                if (cows[j].y < cows[i].y) continue;

            }
        }
    }
}