#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int s[10000], v[10000]; // size and value
int n, m; // number of different items and size of knapsack
int f(int i, int avail, int sum) { // avail=number of units of available space, sum=sum of all selected
    if (i == n) {
        return sum;
    }
    if (s[i] <= avail) {
        return max(f(i + 1, avail - s[i], sum + v[i]), f(i + 1, avail, sum));
    }
    return f(i + 1, avail, sum);
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i] >> v[i];
    cout << f(0, m, 0) << endl;
}