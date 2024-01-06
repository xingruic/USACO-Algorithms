#include<bits/stdc++.h>

using namespace std;
int ans;
struct node {
    char c;
    int cnt, depth;
    map<char, node *> ch;
    void print(bool mx = true) {
        for (int i = 0;i < cnt;i++)
            cout << "P\n";
        char b = '_';
        if (ch.size() and mx) {
            b = ch.begin()->first;
            for (auto i : ch)
                if (ch[b]->depth < i.second->depth)
                    b = i.first;

        }
        for (auto i : ch) {
            if (i.first == b) continue;
            cout << i.first << '\n';
            i.second->print(false);
            cout << "-\n";
        }
        if (b != '_') {
            cout << b << '\n';
            ch[b]->print(true);
        }
    }
};
node *root = new node();

void add(string &s) {
    node *r = root;
    for (int i = 0;i < s.size(); i++) {
        char n = s[i];
        if (r->ch.find(n) == r->ch.end()) {
            ans++;
            // create a new node
            r->ch[n] = new node();
            r->ch[n]->c = n;
        }
        r->depth = max(r->depth, int(s.size()) - i - 1);
        r = r->ch[n];
    }
    r->cnt++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 0;i < n;i++) {
        string s;
        cin >> s;
        add(s);
        mx = max(mx, int(s.size()));
    }
    ans *= 2;
    cout << ans + n - mx << endl;
    root->print();
    return 0;
}