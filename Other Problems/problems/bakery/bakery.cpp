#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int T, N, C, M;
struct visitor {
    int c, m;
    long long t;
}v[101];
int main() {
    freopen("bakery.in", "r", stdin);
    freopen("bakery.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> N >> C >> M;
        for (int i = 0; i < N; i++) {
            cin >> v[i].c >> v[i].m >> v[i].t;
        }
        int left = 0, right = 0x7fffffff;
        while (left < right) {
            int mid = (left + right) / 2;

        }
    }
}