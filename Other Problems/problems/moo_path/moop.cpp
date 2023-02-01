#include <cstring>
#include <iostream>
using namespace std;
int n;
int a[100000];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    string path = "";
    for (int i = 0; i < n; i++) {
        path += 'R';
    }
    for (int i = n - 1; i >= 0;) {
        if (a[i] == 1) {
            a[i]--;
            i--;
            path += 'L';
        }
        int j;
        int mnum = 0x7fffffff, mj;
        for (j = i; j >= 0 && a[j] != 1; j--) {
            if (a[j] < mnum) {
                mnum = a[j], mj = j;
            }
        }
        if (mnum == 0x7fffffff)
            mnum = -1;
        if (a[j] == 1 || j < 1)
            j++;
        int diff = i - j + 1;
        for (; j <= i; j++) {
            a[j] -= (mnum - 1);
        }
        for (int k = 0; k < mnum / 2; k++) {
            for (int j = 0; j < diff; j++)
                path += 'L';
            for (int j = 0; j < diff; j++)
                path += 'R';
        }
        // for (j = 0; j < n; j++)
        //     cout << a[j] << ' ';
        // cout << endl;
    }
    cout << path << endl;
}