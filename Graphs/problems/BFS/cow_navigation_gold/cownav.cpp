#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int N;
char barn[21][21];
int main() {
    freopen("cownav.in", "r", stdin);
    freopen("cownave.out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> barn[i][j];
        }
    }
}