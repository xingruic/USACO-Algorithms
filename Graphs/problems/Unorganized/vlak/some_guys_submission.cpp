#include <bits/stdc++.h>
using namespace std;
const int maxn = 0x7fffffff;

long long n, m; // Nina = 0, Emi = 1

struct Vertex {
    long long next[26];
    long long mask = 0;
    long long output = 0;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};

Vertex trie[maxn];
long long cnt = 1;

void add_trie(string s, int bit) {
    int u = 0;
    for (auto c : s) {
        trie[u].mask |= (1 << bit);
        if (trie[u].next[c - 'a'] == -1) {
            trie[u].next[c - 'a'] = cnt++;
        }
        u = trie[u].next[c - 'a'];

    }
    trie[u].mask |= (1 << bit);
    trie[u].output++;
}

int dfs_trie(int u, int bit) {
    for (int i = 0; i <= 25; i++) {
        int chi = trie[u].next[i];
        if (trie[u].next[i] == -1)
            continue;
        if ((trie[chi].mask & (1ll << (bit ^ 1))) && dfs_trie(chi, bit ^ 1))
            return 0;
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        add_trie(s, 0); // Nina
    }

    cin >> m;
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        add_trie(s, 1); // Emi
    }

    trie[0].mask |= (1 << 1);

    if (!dfs_trie(0, 1))
        cout << "Nina";
    else
        cout << "Emilija";
}