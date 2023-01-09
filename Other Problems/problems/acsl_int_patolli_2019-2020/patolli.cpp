#include <bits/stdc++.h>
using namespace std;
bool marker[53];
bool prime[53];
bool square[53];
int player[3];
int n;
int turning_pts[] = {7, 12, 17, 22, 27, 35, 40, 45, 50};
queue<int> moves;
void listsInit() {
    memset(prime, 1, sizeof(prime));
    memset(square, 0, sizeof(square));
    for (int i = 2; i * i < 53; i++) {
        for (int j = i; i * j < 53; j++) {
            prime[i * j] = 0;
        }
        square[i * i] = 1;
    }
    // cout << prime[29] << endl;
    // for (int i = 1; i <= 52; i++)
    //     cout << prime[i] << ' ';
    // cout << endl;
}
int main() {
    listsInit();
    for (int test = 0; test < 5; test++) {
        memset(marker, 0, sizeof(marker));
        cin >> player[0] >> player[1] >> player[2]; // enemy markers
        marker[player[0]] = marker[player[1]] = marker[player[2]] = 1;
        cin >> player[0] >> player[1] >> player[2]; // player markers (we dont need to store enemy markers)
        marker[player[0]] = marker[player[1]] = marker[player[2]] = 1;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            moves.push(x);
        }
        while (!moves.empty()) {
            sort(player, player + 3);
            if (player[0] == 60) {
                cout << "GAME OVER\n";
                return 0;
            }
            int roll = moves.front();
            moves.pop();
            if (marker[player[0] + roll] || player[0] + roll > 52) {
                // cout << player[0] << ' ' << roll << " bruh" << endl;
                continue;
            }
            // cout << "what " << player[0] << ' ' << roll << ' ';
            marker[player[0]] = 0;
            if (player[0] + roll == 52) {
                player[0] = 60;
                continue;
            }
            if (prime[player[0] + roll]) {
                // cout << "prime -> ";
                int i;
                for (i = player[0] + roll; i < player[0] + roll + 6; i++) {
                    if (i + 1 == 53 || marker[i + 1])
                        break;
                }
                marker[i] = 1;
                player[0] = i;
            } else if (square[player[0] + roll]) {
                // cout << "square -> ";
                int i;
                for (i = player[0] + roll; i > player[0] + roll - 6; i--) {
                    if (i - 1 == 0 || marker[i - 1])
                        break;
                }
                marker[i] = 1;
                player[0] = i;
            } else {
                bool doStep9 = 0;
                for (int point : turning_pts) {
                    if (player[0] < point && player[0] + roll > point) {
                        doStep9 = 1;
                        break;
                    }
                }
                if (doStep9) {
                    int i;
                    bool available = 0;
                    for (i = player[0] + roll; i >= player[0]; i--) {
                        if (i / roll * roll == i && !marker[i]) {
                            // cout << "i=" << i << ' ';
                            available = 1;
                            break;
                        }
                    }
                    // cout << "availiable=" << available << ' ';
                    if (available)
                        marker[i] = 1, player[0] = i;
                    else
                        marker[player[0]] = 1;
                } else
                    marker[player[0] + roll] = 1, player[0] += roll;
            }
            // cout << player[0] << endl;
        }
        sort(player, player + 3);
        if (player[0] == 60) {
            cout << "GAME OVER\n";
            return 0;
        }
        cout << player[0];
        if (player[1] < 60)
            cout << ' ' << player[1];
        if (player[2] < 60)
            cout << ' ' << player[2];
        cout << endl;
    }
}