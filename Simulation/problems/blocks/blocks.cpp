#include <bits/stdc++.h>
using namespace std;
int n;
struct board {
    string a, b;
    int acnt[26] = {0}, bcnt[26] = {0};
} boards[100];
int cnt[26] = {0};
int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> boards[i].a >> boards[i].b;
    }
    for (char c = 'a'; c <= 'z'; c++) {
        for (int i = 0; i < n; i++) {
            for (char j : boards[i].a) {
                if (c == j) {
                    boards[i].acnt[c - 'a']++;
                }
            }
            for (char j : boards[i].b) {
                if (c == j) {
                    boards[i].bcnt[c - 'a']++;
                }
            }
        }
    }
    for (int c = 0; c < 26; c++) {
        for (int i = 0; i < n; i++) {
            cnt[c] += max(boards[i].acnt[c], boards[i].bcnt[c]);
        }
        cout << cnt[c] << endl;
    }
}