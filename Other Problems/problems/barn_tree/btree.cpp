#include <bits/stdc++.h>
using namespace std;
int n;
int h[200001];
int avg = 0;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        avg += h[i];
    }
    avg /= n;
    
}