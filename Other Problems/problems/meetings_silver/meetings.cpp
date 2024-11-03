#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int N, L;
const int nmax = 50001;
struct cow {
    long long pausetil = 0; // pause processing until (collision or arrival)
    int w, x;
    bool plus;
};
vector<cow> cows;
bool cmp(cow &a, cow &b) {
    return a.x < b.x;
}
int main() {
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);
    cin >> N >> L;
    cows.resize(N);

    int wtarget = 0;

    for (int i = 0, t; i < N; i++) {
        cin >> cows[i].w >> cows[i].x >> t;
        wtarget += cows[i].w;
        cows[i].plus = t > 0;
    }
    sort(cows.begin(), cows.end(), cmp);

    wtarget = (wtarget + 1) / 2;

    for (int i = 0; i < N; i++) {
        cout << cows[i].x << " " << cows[i].plus << endl;
    }
    cout << "=====================" << endl;

    int cnt = 0;
    long long mint, t = 0;
    int lb = 0, rb = N;
    int wsum = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    while (lb < rb) {
        while (!pq.empty() && pq.top() <= t) {
            pq.pop();
            cnt++;
        }

        mint = LONG_MAX;

        if (cows[lb].pausetil <= t && !cows[lb].plus) {
            // cout << "ABC" << endl;
            cows[lb].pausetil = t + cows[lb].x;
            cows[lb].x = 0;
            mint = min(mint, cows[lb].pausetil);
        }
        if (cows[rb - 1].pausetil <= t && cows[rb - 1].plus) {
            cows[rb - 1].pausetil = t + L - cows[rb - 1].x;
            cows[rb - 1].x = L;
            mint = min(mint, cows[rb - 1].pausetil);
        }

        for (int i = lb; i < rb; i++) {
            if (cows[i].pausetil < t) {
                if (cows[i].plus) {
                    cows[i].x += t - cows[i].pausetil;
                } else {
                    cows[i].x -= t - cows[i].pausetil;
                }
            }
        }
        // cout << "t=" << t << endl;
        // cout << lb << ' ' << rb << endl;
        for (int i = lb; i < rb - 1; i++) {
            if (t < cows[i].pausetil) {
                mint = min(mint, cows[i].pausetil);
                continue;
            }
            if (t < cows[i + 1].pausetil) {
                mint = min(mint, cows[i + 1].pausetil);
                continue;
            }
            if (cows[i].plus && !cows[i + 1].plus) {
                // cout << cows[i].x << " <-> " << cows[i + 1].x << endl;
                int d = cows[i + 1].x - cows[i].x;
                if (d % 2) {
                    cows[i].x += d / 2;
                    cows[i + 1].x -= d / 2;
                    cows[i].pausetil = cows[i + 1].pausetil = t + d / 2 + 1;
                } else {
                    cows[i].x = cows[i + 1].x = (cows[i].x + cows[i + 1].x) / 2;
                    cows[i].pausetil = cows[i + 1].pausetil = t + d / 2;
                }
                mint = min(mint, cows[i].pausetil);
                cows[i].plus = false;
                cows[i + 1].plus = true;
                pq.push(cows[i].pausetil);
            }
        }
        // for (int i = lb;i < rb;i++)
        //     cout << cows[i].x << ' ' << cows[i].plus << ' ' << cows[i].pausetil << endl;
        // cout << " > " << cows[lb].pausetil << ' ' << cows[rb - 1].pausetil << ' ' << mint << endl;
        if (mint >= cows[lb].pausetil && cows[lb].x == 0) {
            // cout << cows[lb].pausetil << ' ' << cows[lb].plus << endl;
            wsum += cows[lb].w;
            lb++;
        }
        if (mint >= cows[rb - 1].pausetil && cows[rb - 1].x == L) {
            // cout << cows[rb - 1].pausetil << ' ' << cows[rb - 1].plus << endl;
            wsum += cows[rb - 1].w;
            rb--;
        }
        // cout << "priority queue:\n";
        // for (int i : pq.__get_container()) cout << i << ' ';
        // cout << endl;
        // cout << "wsum=" << wsum << endl;
        t = mint;
        // cout << endl;
        if (wsum >= wtarget) break;
        cout << lb << ' ' << rb << endl;
    }
    // cout << "=====================" << endl;
    // for (int i = 0; i < N; i++) {
    //     cout << cows[i].x << " " << cows[i].plus << ' ' << cows[i].pausetil << endl;
    // }
    cout << cnt << endl;
}