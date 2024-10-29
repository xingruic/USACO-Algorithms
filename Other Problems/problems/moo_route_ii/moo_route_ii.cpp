#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int N, M;
const int mmax = 2e5 + 1;

int lay[mmax];

struct Flight {
    bool *used; // if bfs already used this flight
    int n, t; // --> airport n at time t
    Flight(int n, int t) :n(n), t(t), used(new bool) { *used = false; }
    Flight() {}
    bool operator>(const Flight &f) const { return t > f.t; }
};
struct cmp {
    bool operator()(const pair<int, Flight> &x, const pair<int, Flight> &y) const {
        if (x.first == y.first) {
            if (x.second.n == y.second.n) {
                return x.second.t < y.second.t;
            } else {
                return x.second.n < y.second.n;
            }
        }
        return x.first < y.first;
    }
};
set<pair<int, Flight>, cmp> flights[mmax];
queue<pair<int, int> > arrival; // arrive at airport p.first at time p.second
int earliest[mmax];
int main() {
    // freopen("Silver Feb 23/3.in", "r", stdin);
    // freopen("moo_route_ii.out", "w", stdout);
    memset(earliest, 0x7f, sizeof(earliest));
    cin >> N >> M;
    {
        int c, d, r, s;
        for (int i = 1; i <= M; i++) {
            cin >> c >> d >> r >> s;
            flights[c].insert(make_pair(d, Flight(r, s))).second;
        }
        for (int i = 1; i <= N; i++) {
            cin >> lay[i];
        }
    }
    // for (int i = 1; i <= M; i++) {
    //     cout << "==================\n";
    //     cout << "Airport " << i << endl;
    //     for (auto k : flights[i]) {
    //         cout << k.first << ' ' << k.second.n << ' ' << k.second.t << ' ' << *(k.second.used) << endl;
    //     }
    // }
    arrival.push(make_pair(1, 0));
    bool first = true;
    while (!arrival.empty()) {
        // .first = airport #
        // .second = arrival time
        pair<int, int> ar = arrival.front();
        arrival.pop();
        int port = ar.first;
        int atime = ar.second;

        earliest[port] = min(earliest[port], atime);

        // cout << "Arrived at airport " << port << " at time " << atime << endl;

        if (!first) atime += lay[port];
        else first = false;

        // cout << "After layover, time = " << atime << endl;

        auto flight = flights[port].lower_bound(make_pair(atime, Flight()));
        for (; flight != flights[port].end(); flight++) {
            if (*(flight->second.used)) {
                break;
            }
            *(flight->second.used) = true;
            arrival.push(make_pair(flight->second.n, flight->second.t));

            // cout << "push " << flight->second.n << ' ' << (flight->second.t) << endl;
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << (earliest[i] > 0x77777777 ? -1 : earliest[i]) << endl;
    }
}