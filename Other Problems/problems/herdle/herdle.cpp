#include <bits/stdc++.h>
using namespace std;
char correct[3][3], guess[3][3];
int cnt_correct['Z' + 1], cnt_guess['Z' + 1];
int main() {
    // freopen("herdle.in", "r", stdin);
    // freopen("herdle.out", "w", stdout);
    memset(cnt_correct, 0, sizeof(cnt_correct));
    memset(cnt_guess, 0, sizeof(cnt_guess));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            correct[i][j] = getchar();
        getchar();
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            guess[i][j] = getchar();
        getchar();
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (c == correct[i][j])
                    cnt_correct[c]++;
            }
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (c == guess[i][j])
                    cnt_guess[c]++;
            }
        }
    }
    int cnt_green = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (correct[i][j] == guess[i][j]) {
                cnt_correct[correct[i][j]]--;
                cnt_guess[guess[i][j]]--;
                cnt_green++;
            }
        }
    }
    cout << cnt_green << endl;
    int cnt_yellow = 0;
    for (char c = 'A'; c <= 'Z'; c++) {
        cnt_yellow += min(cnt_guess[c], cnt_correct[c]);
    }
    cout << cnt_yellow << endl;
}