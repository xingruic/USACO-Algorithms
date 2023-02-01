#include <iostream>
using namespace std;
int main() {
    string sub = "subsequence";
    string str = "subs9equ6e3nc1e";
    int j = 0;
    for (int i = 0; i < sub.size(); i++) {
        for (; str[j] != sub[i] && j < str.size(); j++)
            ;
        if (j == str.size()) {
            // no subsequence
            cout << "no" << endl;
            exit(0);
        }
        j++;
    }
    cout << "ok" << endl;
}