#include <algorithm>
#include <iostream>
using namespace std;
int lcs(string s1, string s2, int n1, int n2) {
    if (n1 == 0 || n2 == 0)
        return 0;
    if (s1[n1 - 1] == s2[n2 - 1])
        return lcs(s1, s2, n1 - 1, n2 - 1) + 1;
    return max(lcs(s1, s2, n1, n2 - 1), lcs(s1, s2, n1 - 1, n2));
}
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2, s1.size(), s2.size()) << endl;
}