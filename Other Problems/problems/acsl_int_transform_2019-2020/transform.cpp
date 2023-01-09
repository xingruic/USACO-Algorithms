#include <bits/stdc++.h>
using namespace std;
vector<int> n;
int p;
int main() {
    for (int test = 0; test < 5; test++) {
        n.clear();
        char c = '.';
        while (c != ' ') {
            c = getchar();
            if (c>='0'&&c<='9')
                n.push_back(c - '0');
        }
        cin >> p;
        // cout<<p<<endl;
        // for(int i=0; i<n.size(); i++){
        //     cout<<n[i]<<' ';
        // }cout<<endl;
        int idx=n.size()-p;
        int np = n[idx];
        for (int i = 0; i < idx; i++) {
            n[i] += np;
        }
        for (int i = idx + 1; i < n.size(); i++) {
            n[i] -= np;
        }
        for (int i = 0; i < n.size(); i++) {
            if (i == idx)
                n[i] = np;
            if (n[i] < 0)
                n[i] = -n[i];
            n[i] %= 10;
        }
        for (int i = 0; i < n.size(); i++)
            cout << n[i];
        cout << endl;
    }
}