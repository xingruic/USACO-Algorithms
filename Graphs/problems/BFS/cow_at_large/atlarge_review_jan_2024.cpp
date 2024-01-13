#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
struct barn {
    vector<barn *> path;
    int i, fmr = 0;
    bool ex, bes = 0;
    barn(int i) :i(i) {}
    void addpath(barn *b) {
        path.push_back(b);
        ex = path.size() == 1;
    }
};
vector<barn *> farm;
int n, k;
void printq(queue<barn *> q) {
    while (!q.empty()) {
        cout << q.front()->i + 1 << ' ';
        q.pop();
    }cout << endl;
}
int main() {
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);
    cin >> n >> k;
    farm.resize(n);
    for (int i = 0; i < n; i++) {
        farm[i] = new barn(i);
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        farm[a]->addpath(farm[b]);
        farm[b]->addpath(farm[a]);
    }
    queue<barn *> bes;
    farm[k - 1]->bes = true;
    bes.push(farm[k - 1]);
    queue<barn *> fmr;
    for (int i = 0; i < n; i++) {
        if (farm[i]->ex) {
            farm[i]->fmr = i + 1;
            fmr.push(farm[i]);
        }
    }
    int cnt = 0;
    while (!bes.empty()) {
        barn *t;
        if (!bes.empty()) {
            for (int i = bes.size();i--;) {
                t = bes.front();
                bes.pop();
                if (t->fmr) continue;
                for (barn *b : t->path) {
                    if (!b->bes) {
                        b->bes = true;
                        bes.push(b);
                    }
                }
            }
        }
        if (!fmr.empty()) {
            for (int i = fmr.size(); i--;) {
                t = fmr.front();
                fmr.pop();
                if (t->bes) {
                    cnt++;
                    continue;
                }
                for (barn *b : t->path) {
                    if (!b->fmr) {
                        b->fmr = t->fmr;
                        fmr.push(b);
                    } else if (b->fmr != t->fmr) {
                        break;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
}