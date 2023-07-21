#include <bits/stdc++.h>
using namespace std;
int n;
string in;
set<int> db;
inline int _hash(string &s) {
    int add = 131;
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        res = res * i + s[i] + add;
    }
    return res % 100000007;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in;
        if (db.count(_hash(in)) == 0) {
            db.insert(_hash(in));
            cout << "OK" << endl;
        } else {
            int j;
            string h;
            for (j = 1; db.count(_hash(h = (in + to_string(j)))); j++)
                ;
            db.insert(_hash(h));
            cout << h << endl;
        }
    }
}