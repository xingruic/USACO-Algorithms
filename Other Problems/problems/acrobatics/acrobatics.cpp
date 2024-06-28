#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int n, m, k;
pair<int, int> d[200000]; // first = w; second = a
struct Cmp {
    bool operator()(pair<int, int> *a, pair<int, int> *b) const {
        return (a->first) > (b->first);
    }
};
set<pair<int, int> *, Cmp> tower; // first = w of the cow on top; second = a
int cnt = 0; // answer
int main() {
    // freopen("acrobatics.in", "r", stdin);
    // freopen("acrobatics.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> d[i].first >> d[i].second;
    }
    {
        pair<int, int> *t = new pair<int, int>(make_pair(0x7fffffff, m));
        tower.insert(t); // <-------------- might have sigsegv, watch out
    }
    sort(d, d + n, [](pair<int, int> a, pair<int, int> b) {return a.first > b.first;});
    for (int i = 0; i < n; i++) {
        // for (pair<int, int> *k : tower) {
        //     cout << (k->first) << ' ' << (k->second) << endl;
        // }
        // cout << "============\n";
        int total = 0;
        for (auto j = tower.begin(); j != tower.end() && d[i].second > 0;) {
            auto tmp = j;
            j++;
            if (((*tmp)->first) - (d[i].first) >= k) { // then we can put cows of weight d[i].second onto this group of towers
                if (((*tmp)->second) > (d[i].second)) {
                    // cout << "A\n";
                    (*tmp)->second -= d[i].second;
                    total += d[i].second;
                    break;
                } else {
                    // cout << "B\n";
                    d[i].second -= (*tmp)->second;
                    total += (*tmp)->second;
                    tower.erase(tmp);
                }
            }
        }
        // cout << "before insert" << endl;
        // for (pair<int, int> *k : tower) {
        //     cout << (k->first) << ' ' << (k->second) << endl;
        // }
        cnt += total;
        pair<int, int> *t = new pair<int, int>(make_pair(d[i].first, total));
        tower.insert(t); // <-------------- might have sigsegv, watch out
        // cout << "after insert" << endl;
        // for (pair<int, int> *k : tower) {
        //     cout << (k->first) << ' ' << (k->second) << endl;
        // }
    }
    // for (pair<int, int> *k : tower) {
    //     cout << (k->first) << ' ' << (k->second) << endl;
    // }
    // cout << "============\n";
    cout << cnt << endl;
}