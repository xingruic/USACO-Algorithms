#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
const int maxn = 10e5;
struct cow {
    int s, a, t;
};
class cmp {
public:
    bool operator()(cow &a, cow &b) {
        return a.s > b.s; // rank based on seniority
    }
};
int n;
cow c[maxn];
int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        c[i].s = i;
        cin >> c[i].a >> c[i].t;
    }
    sort(c, c + n, [](cow &a, cow &b) {return a.a < b.a;});
    // for (int i = 0; i < n; i++) {
    //     cout << c[i].s << ' ' << c[i].a << ' ' << c[i].t << endl;
    // }cout << endl;
    priority_queue<cow, vector<cow>, cmp> pq;
    pq.push(c[0]);
    int idx = 1;
    int time = c[0].a;
    int mwait = 0;
    while (!pq.empty() || idx < n) {
        if (pq.empty()) {
            pq.push(c[idx]);
            time = c[idx++].a;
        }
        mwait = max(mwait, time - pq.top().a); // compute top cow's wait time
        // cout << time << ' ' << pq.top().t << ' ';
        time += pq.top().t; // top cow eats
        pq.pop(); // top cow leaves
        while (c[idx].a <= time && idx < n) { // put all the cows that arrived while top cow was eating
            pq.push(c[idx]);
            idx++;
        }
        // cout << time << endl;
    }
    cout << mwait << endl;
}