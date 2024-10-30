#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int N;
const int nmax = 1001;
struct cow {
    bool stopped = 0;
    int x, y, idx;
    cow(int x, int y, int idx) : x(x), y(y), idx(idx) {}
};
struct ncmp {
    bool operator()(cow *x, cow *y) {
        if (x->x == y->x) {
            return (x->y) < (y->y);
        }
        return (x->x) < (y->x);
    }
};
struct ecmp {
    bool operator()(cow *x, cow *y) {
        if (x->y == y->y) {
            return (x->x) < (y->x);
        }
        return (x->y) < (y->y);
    }
};

set<cow *, ncmp> north;
set<cow *, ecmp> east;

int numstopped[nmax];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        char dir;
        int x, y;
        cin >> dir >> x >> y;
        if (dir == 'E') {
            east.insert(new cow(x, y, i));
        } else {
            north.insert(new cow(x, y, i));
        }
    }

    memset(numstopped, 0, sizeof(numstopped));

    for (cow *nc : north) {
        for (cow *ec : east) {
            if (ec->stopped) continue;
            if (ec->y < nc->y || nc->x < ec->x) continue;
            int iy = ec->y; // east-facing cow's y is constant
            int ix = nc->x; // north-facing cow's x is constant
            // cout << (nc->idx) << " and " << (ec->idx) << " meet at " << ix << ',' << iy;
            if (iy - nc->y > ix - ec->x) {
                numstopped[ec->idx] += 1 + numstopped[nc->idx];
                nc->stopped = true;
                // cout << " and " << (nc->idx) << " is stopped" << endl;
                break;
            } else if (iy - nc->y < ix - ec->x) {
                numstopped[nc->idx] += 1 + numstopped[ec->idx];
                ec->stopped = true;
                // cout << " and " << (ec->idx) << " is stopped" << endl;
            } else {
                // cout << " and they both keep going" << endl;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << numstopped[i] << endl;
    }
}