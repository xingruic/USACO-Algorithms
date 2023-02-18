#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int n, x;
int c[101];
int cc(int i = 1, int sum = 0, vector<int> coins = vector<int>()) {
    if (sum == x) {
        int cnt = 0;
        do {
            cnt++;
        } while (next_permutation(coins.begin(), coins.end()));
        return cnt;
    }
    if (i > n || sum > x) {
        return 0;
    }
    int t = 0;
    t = t + cc(i + 1, sum, coins);
    coins.push_back(c[i]);
    return t + cc(i, sum + c[i], coins);
}
int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    cout << cc() << endl;
}