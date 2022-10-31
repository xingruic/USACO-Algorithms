#include <bits/stdc++.h>
using namespace std;
int k, m, n;
pair<int, int> p[200001]; // second=position, first=tastiness
int f[200001];
int main() {
    cin >> k >> m >> n;
    for (int i = 1; i <= k; i++)
        cin >> p[i].second >> p[i].first;
    for (int i = 1; i <= m; i++)
        cin >> f[i];
}