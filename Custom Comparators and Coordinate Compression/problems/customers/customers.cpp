#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#pragma

using namespace std;

// #define DEBUG_

struct customer {
    // the time that the customer joined/left
    int join, leave;
} c[200000];

int n;
vector<int> indices; // special indices
int diff[400000] = {0}; // difference array between two indices
int psum[400000]; // prefix sum of diff array (which is equal to the special interval's value)

bool cmpj(const customer &x, const customer &y) {
    return x.join < y.join;
}
bool cmpl(const customer &x, const customer &y) {
    return x.leave < y.leave;
}

int getCompressed(int x) {
    int l = 0, r = indices.size() - 1;
    while (l != r) {
        if (indices[(l + r) / 2] > x)
            r = (l + r) / 2 - 1;
        else if (indices[(l + r) / 2] < x)
            l = (l + r) / 2 + 1;
        else
            return (l + r) / 2;
    }
    return l;
}

int main() {
    // freopen("customers.in", "r", stdin);
    // freopen("customers.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i].join >> c[i].leave;
        indices.push_back(c[i].join);
        indices.push_back(c[i].leave);
    }

    sort(indices.begin(), indices.end());

    // use the unique() function to get rid of duplicates, then erase the part afterward which is just leftover
    indices.erase(unique(indices.begin(), indices.end()), indices.end());

#ifdef DEBUG_
    for (int i = 0; i < indices.size(); i++)
        cout << indices[i] << '\t';
    cout << endl;
    for (int i = 0; i < indices.size(); i++) {
        cout << getCompressed(indices[i]) << '\t';
    }
    cout << endl;
    int m = 0;
    for (int i = 0; i < n; i++)
        m = max(max(m, c[i].leave), c[i].join);
    cerr << "maximum value from c[i]: " << m << endl;
#endif

    for (int i = 0; i < n; i++) {
        diff[getCompressed(c[i].join)]++;
        diff[getCompressed(c[i].leave)]--;
    }
    psum[0] = diff[0];
    int maxs = psum[0];
    for (int i = 0; i < indices.size() - 1; i++) {
        psum[i + 1] = psum[i] + diff[i + 1];
        maxs = max(maxs, psum[i + 1]);
        // cerr << psum[i] << ' ';
    }
    // cerr << psum[indsize - 1] << '\n';
    cout << maxs << endl;
}