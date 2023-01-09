#include <bits/stdc++.h>
using namespace std;
string input;
bool cell[4][4];
bool ans[4][4];
vector<string> parse;
void A(bool squig = 0) {
    if (squig) {
        for (int i = 0; i < 4; i++)
            cell[i][0] = 0, cell[i][1] = 0;
    } else {
        for (int i = 0; i < 4; i++)
            cell[i][2] = 0, cell[i][3] = 0;
    }
}
void B(bool squig = 0) {
    if (squig) {
        for (int i = 0; i < 4; i++)
            cell[0][i] = 0, cell[1][i] = 0;
    } else {
        for (int i = 0; i < 4; i++)
            cell[2][i] = 0, cell[3][i] = 0;
    }
}
void C(bool squig = 0) {
    if (squig) {
        for (int i = 0; i < 4; i++)
            cell[i][1] = 0, cell[i][2] = 0;
    } else {
        for (int i = 0; i < 4; i++)
            cell[i][0] = 0, cell[i][3] = 0;
    }
}
void D(bool squig = 0) {
    if (squig) {
        for (int i = 0; i < 4; i++)
            cell[2][i] = 0, cell[1][i] = 0;
    } else {
        for (int i = 0; i < 4; i++)
            cell[0][i] = 0, cell[3][i] = 0;
    }
}
int main() {
    // freopen("v.out", "w", stdout);
    for (int test = 0; test < 5; test++) {
        memset(ans, 0, sizeof(ans));
        parse.clear();
        cin >> input;
        for (int i = 0; !input.empty() && i < input.size(); i++) {
            if (input[i] == '+') {
                parse.push_back(input.substr(0, i));
                input.erase(0, i + 1);
                i = -1;
            }
        }
        parse.push_back(input);
        string s;
        int x, y;
        for (int i = 0; i < parse.size(); i++) {
            memset(cell, 1, sizeof(cell));
            s = parse[i];
            for (int j = 0; j < s.size(); j++) {
                if (s[j] == '~') {
                    j++;
                    switch (s[j]) {
                    case 'A':
                        A(1);
                        break;
                    case 'B':
                        B(1);
                        break;
                    case 'C':
                        C(1);
                        break;
                    default:
                        D(1);
                        break;
                    }
                } else {
                    switch (s[j]) {
                    case 'A':
                        A();
                        break;
                    case 'B':
                        B();
                        break;
                    case 'C':
                        C();
                        break;
                    default:
                        D();
                        break;
                    }
                }
            }
            // cout << s << endl;
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    ans[j][k] |= cell[j][k];
                    // cout << cell[j][k] << ' ';
                }
                // cout << endl;
            }
        }
        // for (int i = 0; i < 4; i++) {
        //     for (int j = 0; j < 4; j++)
        //         cout << ans[i][j] << ' ';
        //     cout << endl;
        // }
        for (int i = 0; i < 4; i++) {
            int out = 0;
            for (int j = 0; j < 4; j++) {
                out <<= 1;
                out += ans[i][j];
            }
            printf("%X", out);
        }
        printf("\n");
    }
    return 0;
}