#include <bits/stdc++.h>
using namespace std;
struct cow {
    int x, y;
    char dir;
};
struct intersect {
    int x = -1, y = -1;
    cow *first;
} inter[50][50];
int n;
cow cows[50];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cows[i].dir >> cows[i].x >> cows[i].y;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cows[i].dir == 'E') {
                if (cows[j].x < cows[i].x)
                    continue;
                if (cows[j].dir == 'N') {
                    if (cows[j].y > cows[i].y)
                        continue;
                    inter[i][j].x = cows[j].x;
                    inter[i][j].y = cows[i].y;
                    if (inter[i][j].y - cows[j].y > inter[i][j].x - cows[i].x)
                        inter[i][j].first = &cows[i];
                    else
                        inter[i][j].first = &cows[j];
                } else if (cows[j].dir == 'S') {
                    if (cows[j].y < cows[i].y)
                        continue;
                    inter[i][j].x = cows[j].x;
                    inter[i][j].y = cows[j].y;
                    if (cows[j].y - inter[j][j].y > inter[i][j].x - cows[i].x)
                        inter[i][j].first = &cows[i];
                    else
                        inter[i][j].first = &cows[j];
                }
            }
            inter[j][i] = inter[i][j];
        }
    }
}