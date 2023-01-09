#include <bits/stdc++.h>
using namespace std;
int n;
int h[200001];
int avg = 0;
int main() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        nodes[i] = (node)malloc(sizeof(Node));
    }
    int root_idx;
    {
        int max_val = -1;
        for (int i = 1; i <= n; i++) {
            cin >> h[i];
            // h[i] = 1;
            if (h[i] > max_val) {
                max_val = h[i];
                root_idx = i;
            }
            avg += h[i];
            nodes[i]->idx = i;
            nodes[i]->x = h[i];
        }
    }
    avg /= n;
}