#include <bits/stdc++.h>
using namespace std;
int n;
struct sensor {
    sensor(string t, int L, int R) : type(t), l(L), r(R) {}
    string type;
    int l, r;
};
vector<sensor> sensors;
int main() {
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    cin >> n;
    string t;
    int l, r;
    for (int i = 0; i < n; i++) {
        cin >> t >> l >> r;
        sensors.push_back(sensor(t, l, r));
    }
    for (int i = 1; i < n; i++) {
        if (sensors[i - 1].type == "none" && sensors[i].type == "none") {
            sensors[i].l = max(sensors[i - 1].l, sensors[i].l);
            sensors[i].r = min(sensors[i - 1].r, sensors[i].r);
            sensors.erase(sensors.begin() + i - 1);
            i--, n--;
        }
    }
    int i;
    for (i = 0; sensors[i].type != "none"; i++)
        ;
    for (; i < n; i++) {
        if (sensors[i].type == "none")
            continue;
        if (sensors[i].type == "on") {
            if (i < n - 1 && sensors[i + 1].type == "none") {
                sensors[i + 1].l = max(sensors[i + 1].l, sensors[i - 1].l + sensors[i].l);
                sensors[i + 1].r = min(sensors[i + 1].r, sensors[i - 1].r + sensors[i].r);
            } else {
                sensors.insert(sensors.begin() + i + 1, sensor("none", sensors[i - 1].l + sensors[i].l, sensors[i - 1].r + sensors[i].r));
                n++;
            }
        } else {
            if (i < n - 1 && sensors[i + 1].type == "none") {
                sensors[i + 1].l = max(sensors[i + 1].l, sensors[i - 1].l - sensors[i].r);
                sensors[i + 1].r = min(sensors[i + 1].r, sensors[i - 1].r - sensors[i].l);
            } else {
                sensors.insert(sensors.begin() + i + 1, sensor("none", sensors[i - 1].l - sensors[i].r, sensors[i - 1].r - sensors[i].l));
                n++;
            }
        }
    }
    for (i = n - 1; sensors[i].type != "none"; i--)
        ;
    for (; i >= 0; i--) {
        if (sensors[i].type == "none")
            continue;
        if (sensors[i].type == "off") {
            if (i > 0 && sensors[i - 1].type == "none") {
                sensors[i - 1].l = max(sensors[i - 1].l, sensors[i + 1].l + sensors[i].l);
                sensors[i - 1].r = min(sensors[i - 1].r, sensors[i + 1].r + sensors[i].r);
            } else {
                sensors.insert(sensors.begin() + i, sensor("none", sensors[i + 1].l + sensors[i].l, sensors[i + 1].r + sensors[i].r));
                n++;
            }
        } else {
            if (i > 0 && sensors[i - 1].type == "none") {
                sensors[i - 1].l = max(sensors[i - 1].l, sensors[i + 1].l - sensors[i].r);
                sensors[i - 1].r = min(sensors[i - 1].r, sensors[i + 1].r - sensors[i].l);
            } else {
                sensors.insert(sensors.begin() + i, sensor("none", sensors[i + 1].l - sensors[i].r, sensors[i + 1].r - sensors[i].l));
                n++;
            }
        }
    }
    // for (i = 0; sensors[i].type != "none"; i++)
    //     ;
    // int tmp = i;
    // for (i--; i >= 0; i--) {
    //     if (sensors[i].type == "on") {
    //         sensors[tmp].r -= sensors[i].l;
    //         sensors[tmp].l -= sensors[i].r;
    //     } else {
    //         sensors[tmp].r += sensors[i].r;
    //         sensors[tmp].l += sensors[i].l;
    //     }
    // }
    // for (sensor s : sensors) {
    //     cout << s.l << ' ' << s.r << ' ' << s.type << endl;
    // }
    cout << sensors.begin()->l << ' ' << sensors.begin()->r << '\n'
         << sensors[n - 1].l << ' ' << sensors[n - 1].r << endl;
}