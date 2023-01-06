#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, n, t;
    for (int line = 0; line < 5; line++) {
        n = "";
        getline(cin, s);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < 'a' || s[i] > 'z') {
                if (s[i] >= 'A' && s[i] <= 'Z')
                    s[i] += 'a' - 'A';
                else {
                    s.erase(i, 1);
                    i--;
                }
            }
        }
        bool f['z' + 1];
        while (!s.empty()) {
            memset(f, 0, sizeof(f));
            t = "";
            for (int i = 0; i < s.size(); i++) {
                if (f[s[i]]) {
                    // cout<<1<<endl;
                    continue;
                } else {
                    // cout<<2<<endl;
                    f[s[i]] = 1;
                    t += s[i];
                    s.erase(i, 1);
                    i--;
                }
            }
            // for (int j = 'a'; j <= 'z'; j++)
            //     cout << f[j] << ' ';-
            // cout << endl;
            sort(t.begin(), t.end());
            n += t;
            // cout<<s<<' '<<t<<endl;
        }
        for(int i=1; i<n.size(); i++){
            if(n[i]==n[i-1]){
                n.erase(i,1);
                i--;
            }
        }
        cout << n << endl;
    }
}