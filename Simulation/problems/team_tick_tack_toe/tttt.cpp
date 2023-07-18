#include <bits/stdc++.h>
using namespace std;
char board[3][3];
bool indiv[26] = {0};
bool team[26][26];
int main() {
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    memset(team, 0, sizeof(team));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cin >> board[i][j];
    }
    for (int i = 0; i < 3; i++) {
        bool h = 1;
        for (int j = 1; j < 3; j++) {
            if (board[i][j] != board[i][j - 1]) {
                h = 0;
                break;
            }
        }
        if (h)
            indiv[board[i][0] - 'A'] = 1;
    }
    for (int i = 0; i < 3; i++) {
        bool v = 1;
        for (int j = 1; j < 3; j++) {
            if (board[j][i] != board[j - 1][i]) {
                v = 0;
                break;
            }
        }
        if (v)
            indiv[board[0][i] - 'A'] = 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        indiv[board[0][0] - 'A'] = 1;
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2])
        indiv[board[1][1] - 'A'] = 1;
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        cnt += indiv[i];
    }
    cout << cnt << endl;
    set<char> s1, s2;
    for (int i = 0; i < 3; i++) {
        s1.clear(), s2.clear();
        for (int j = 0; j < 3; j++) {
            s1.insert(board[i][j]);
            s2.insert(board[j][i]);
        }
        if (s1.size() == 2) {
            // cout << "s1 " << *s1.begin() << ' ' << *(++s1.begin()) << endl;
            team[(*s1.begin()) - 'A'][(*(++s1.begin())) - 'A'] = 1;
        }
        if (s2.size() == 2) {
            // cout << "s2 " << *s2.begin() << ' ' << *(++s2.begin()) << endl;
            team[(*s2.begin()) - 'A'][(*(++s2.begin())) - 'A'] = 1;
        }
    }
    if (board[0][0] != board[1][1]) {
        if (board[2][2] == board[1][1] || board[2][2] == board[0][0])
            team[board[0][0] - 'A'][board[1][1] - 'A'] = 1;
    } else if (board[1][1] != board[2][2]) {
        team[board[0][0] - 'A'][board[2][2] - 'A'] = 1;
    }
    if (board[0][2] != board[1][1]) {
        if (board[2][0] == board[1][1] || board[2][0] == board[0][2])
            team[board[0][2] - 'A'][board[1][1] - 'A'] = 1;
    } else if (board[1][1] == board[2][0]) {
        team[board[0][2] - 'A'][board[2][0] - 'A'] = 1;
    }
    cnt = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (team[i][j] || team[j][i])
                cnt++;
        }
    }
    cout << cnt << endl;
}