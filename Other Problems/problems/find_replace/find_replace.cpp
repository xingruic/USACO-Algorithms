#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int t;
string s, f;
char conv['z' + 1];
int main() {
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        memset(conv, '0', sizeof(conv));
        cin >> s >> f;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != f[i]) {
                if (conv[i] == '0') {
                    conv[s[i]] = f[i];
                }
            }
        }
        bool imposs = 0;
        for (int i = 0; i < n; i++) {
            if (conv[s[i]] != '0' && conv[s[i]] != f[i]) {
                imposs = 1;
                cout << -1 << endl;
                break;
            }
        }
        if (imposs)
            continue;
        int cnt = 0, overlap = 0, loops = 0;
        for (int i = 'A'; i <= 'Z'; i++) {
            if (conv[i] != '0') {
                cnt++;
                if (conv[conv[i]] != '0') {
                    overlap++;
                }
            }
        }
        for (int i = 'a'; i <= 'z'; i++) {
            if (conv[i] != '0') {
                cnt++;
                if (conv[conv[i]] != '0') {
                    overlap++;
                }
            }
        }
        for (int i = 'A'; i <= 'Z'; i++) {
            if (conv[i] != '0') {
                vector<char> got;
                char j = i;
                bool loop = 1;
                while (find(got.begin(), got.end(), j) == got.end()) {
                    if (j == '0') {
                        loop = 0;
                        break;
                    }
                    got.push_back(j);
                    j = conv[j];
                }
                if (loop) {
                    loops++;
                    auto p = find(got.begin(), got.end(), j);
                    p++;
                    got.erase(got.begin(), p);
                    for (char each : got) {
                        conv[each] = '0';
                    }
                }
            }
        }
        for (int i = 'a'; i <= 'z'; i++) {
            if (conv[i] != '0') {
                vector<char> got;
                char j = i;
                bool loop = 1;
                while (find(got.begin(), got.end(), j) == got.end()) {
                    if (j == '0') {
                        loop = 0;
                        break;
                    }
                    got.push_back(j);
                    j = conv[j];
                }
                if (loop) {
                    loops++;
                    auto p = find(got.begin(), got.end(), j);
                    p++;
                    got.erase(got.begin(), p);
                    for (char each : got) {
                        conv[each] = '0';
                    }
                }
            }
        }
        cout << cnt + overlap - loops << endl;
    }
}