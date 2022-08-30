#include <algorithm>
#include <iostream>

using namespace std;

int N, M, R;
int c[100000];
struct order {
    int gallons, price;
} orders[100000];
int r[100000];
long long milkinc[100000] = {0}; // the income from milk from the first n cows with the most milk
long long rinc[100000] = {0};
bool my_cmp(const order &a, const order &b) {
    return a.price > b.price;
}
int main() {
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    cin >> N >> M >> R;
    for (int i = 0; i < N; i++)
        cin >> c[i];
    for (int i = 0; i < M; i++) {
        cin >> orders[i].gallons >> orders[i].price;
    }
    for (int i = 0; i < R; i++)
        cin >> r[i];
    sort(c, c + N, greater<int>());
    sort(r, r + N, greater<int>());
    sort(orders, orders + M, my_cmp);
    {
        int j = 0;
        for (int i = 0; i < N; i++) {
            if (i > 0)
                milkinc[i] = milkinc[i - 1];
            for (; j < M; j++) {
                if (c[i] > orders[j].gallons) {
                    milkinc[i] += orders[j].gallons * orders[j].price;
                    c[i] -= orders[j].gallons;
                } else {
                    break;
                }
            }
            milkinc[i] += c[i] * orders[j].price;
            orders[j].gallons -= c[i];
            // cerr << milkinc[i] << ' ';
        }
        // cerr << endl;
    }
    rinc[0] = r[0];
    // cerr << rinc[0] << ' ';
    for (int i = 1; i < R; i++) {
        rinc[i] = rinc[i - 1] + r[i];
        // cerr << rinc[i] << ' ';
    }
    // cerr << endl;
    long long maxinc = 0;
    int x = -1;
    for (int i = 0; i < N; i++) {
        if (maxinc < milkinc[i] + rinc[N - i - 2]) {
            maxinc = milkinc[i] + rinc[N - i - 2];
            x = i;
        }
    }
    // cerr << x << ' ' << milkinc[x] << ' ' << rinc[N - x - 2] << endl;
    cout << maxinc << endl;
}