#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int maxn = 0x10001;
int n, k;
int y[maxn];
set<int> ox_used;
typedef struct Gap {
    int ox, size;
    Gap(int ox, int size) :ox(ox), size(size) {}
} gap;
vector<gap> gaps;
int main() {
    fill(y, y + maxn, -1);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> y[i];
        ox_used.insert(y[i] / 12 + 1);
    }
    int prev_ox = 0;
    for (int i : ox_used) {
        gaps.push_back(gap(i - 1, i - 1 - prev_ox));
        prev_ox = i;
    }
    sort(gaps.begin(), gaps.end(), [](gap &a, gap &b) {
        return a.size > b.size;
        });
    k--; // we have to use one jump to get to the very beginning
    int i = 0;
    // for (gap i : gaps) {
    //     cout << i.ox << ' ' << i.size << '\n';
    // }
    for (auto itr = gaps.begin(); itr != gaps.end() && i < k; i++) {
        itr = gaps.erase(itr);
    }
    // for (gap i : gaps) {
    //     cout << i.ox << ' ' << i.size << '\n';
    // }

}