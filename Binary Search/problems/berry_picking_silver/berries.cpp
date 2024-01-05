#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
const int maxn = 1000;
int n, k;
int b[maxn];
int main() {
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(b, b + n, greater());
}