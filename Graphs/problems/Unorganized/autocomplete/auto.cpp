#include<bits/stdc++.h>
using namespace std;
int w, n;
struct node {
    char c;
    vector<node *> children;
    string dword = "~";
    node(char c) :c(c) {};
};
vector<string> dict;
vector<pair<int, string>> words;
vector<node *> wordn;
node *root = new node(0);
node *construct(string s, node *cur) {
    if (s.empty()) return cur;
    char f = s[0];
    for (node *child : cur->children) {
        if (f == child->c) {
            return construct(s.substr(1), child);
        }
    }
    node *nf = new node(f);
    cur->children.push_back(nf);
    return construct(s.substr(1), nf);
}
void alphabetical(node *cur) {
    sort(cur->children.begin(), cur->children.end(), [](node *a, node *b) {return a->c < b->c;});
    // for (node *child : cur->children) cout << child->c << ' ';
    // cout << endl;
    for (node *child : cur->children) alphabetical(child);
}
void preorder(node *cur) {
    cout << cur->dword << ' ';
    for (node *child : cur->children) {
        preorder(child);
    }
}
int cnt;
bool printd(node *cur) {
    if (cur->dword != "~") {
        if (cnt) cnt--;
        else {
            cout << distance(dict.begin(), find(dict.begin(), dict.end(), cur->dword)) + 1 << endl;
            return 1;
        }
    }
    bool ret = 0;
    for (node *child : cur->children) {
        ret |= printd(child);
        if (ret) break;
    }
    return ret;
}
int main() {
    freopen("auto.in", "r", stdin);
    freopen("auto.out", "w", stdout);
    cin >> w >> n;
    dict.resize(w);
    for (int i = 0; i < w; i++) {
        cin >> dict[i];
        construct(dict[i], root)->dword = dict[i];
    }
    words.resize(n);
    wordn.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i].first >> words[i].second;
        wordn[i] = construct(words[i].second, root);
    }
    alphabetical(root);
    // preorder(root);
    // cout << endl;
    for (int i = 0; i < n; i++) {
        cnt = words[i].first - 1;
        if (!printd(wordn[i])) cout << -1 << endl;
    }
}