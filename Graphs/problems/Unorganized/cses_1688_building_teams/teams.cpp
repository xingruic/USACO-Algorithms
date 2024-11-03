#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int n, m;
int f[100001]; // f[i]=j, i and j are friends
int main() {
    memset(f, 0, sizeof(f));
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if (f[a] != -1 || f[b] != -1) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        f[a] = b;
        f[b] = a;
    }
}