#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int N, M;
const int nmax = 100001;
int comp[nmax];
int hmilk[nmax];
vector<int> edge[nmax];
int group = 1;
void assign_component(int n) {
    for (int i : edge[n]) {
        if (comp[i] != -1) {
            continue;
        }
        if (hmilk[i] != hmilk[n]) {
            comp[i] = group++;
        } else {
            comp[i] = comp[n];
        }
        assign_component(i);
    }
}
int main() {
    fill(comp, comp + nmax, -1);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    cin >> N >> M;
    getchar();
    for (int i = 1; i <= N; i++) {
        hmilk[i] = (getchar() == 'H');
    }
    int a, b;
    for (int i = 1; i < N; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    comp[1] = 0;
    assign_component(1);
    // for (int i = 1; i <= N; i++) {
    //     cout << comp[i] << ' ';
    // }cout << endl;
    getchar();
    char c;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b >> c;
        // cout << c << ' ' << a << ',' << b << ' ' << comp[a] << ',' << comp[b] << endl;;
        if (comp[a] == comp[b]) {
            cout << (hmilk[a] == (c == 'H'));
        } else {
            cout << 1;
        }
        // cout << endl;
    }cout << endl;
}