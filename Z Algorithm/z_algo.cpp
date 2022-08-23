/******
good tutorial:
https://ivanyu.me/blog/2013/10/15/z-algorithm/
******/
#include <iostream>
#include <string>
using namespace std;
int z[500000] = {0};
void z_algo(const string &s) {
    z[0] = s.size();
    int L = -1, R = -1; // set L and R to -1 so that our loop calculates them
    for (int i = 1; i < s.size(); i++) {
        if (i > R) { // if R is below i
            L = i, R = i; // start from i
            while (R < s.size() && s[R - L] == s[R]) { // while R isn't out of range && [L,R] makes a prefix
                R++;
            }
            z[i] = R - L; // z[i]=length([L,R])
        } else {
            // TODO: Understand this part
            int k = i - L;
            if (z[k] < R - i + 1) {
                z[i] = z[k];
            } else {
                L = i;
                while (R < n && s[R - L] == s[R]) {
                    R++;
                }
                z[i] = R - L;
                R--;
            }
        }
    }
}
int main() {
    string s;
    cin >> s;
}