#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int n;
int cowcnt = 0;
struct cow {
    int x, y, idx;
    cow() {
        idx = cowcnt++;
    }
};
struct edge {
    cow *a, *b;
    int dist = -1; // stores (distance between a and b)^2
    edge(cow *a, cow *b) :a(a), b(b) {
        dist = (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y);
    }
    edge() {
        a = new cow();
        b = a;
    }
};
vector<cow> cows;
vector<edge *> edges;
vector<bool> cowin;
// vector<vector<edge *>> fromcow;
int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> n;
    cows.resize(n);
    cowin.resize(n);
    // fromcow.resize(n);
    for (cow &i : cows) {
        cin >> i.x >> i.y;
    }
    edge *t;
    for (int i = 0; i < cows.size(); i++) {
        for (int j = i + 1; j < cows.size(); j++) {
            t = new edge(&cows[i], &cows[j]);
            // fromcow[i].push_back(t);
            // fromcow[j].push_back(t);
            edges.push_back(t);
        }
    }
    sort(edges.begin(), edges.end(), [](edge *a, edge *b) {return a->dist < b->dist;});
    int incl;
    for (incl = 0; incl < edges.size(); incl++) {
        cowin[edges[incl]->a->idx] = cowin[edges[incl]->b->idx] = 1;
        if (count(cowin.begin(), cowin.end(), true) == n) {
            break;
        }
    }
    cout << edges[incl]->dist << endl;
}