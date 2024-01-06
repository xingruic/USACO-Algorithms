#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
// #include<bits/stdc++.h>
using namespace std;
int n, m; // on the problem statement, these are r and c respectively.
vector<pair<int, int>> island[16];
char grid[51][51];
void dfs1(int i, int j, int id) {
    grid[i][j] = id;
    island[id].push_back(make_pair(i, j));
    if (i < n && grid[i + 1][j] == 'X') {
        dfs1(i + 1, j, id);
    }
    if (i > 1 && grid[i - 1][j] == 'X') {
        dfs1(i - 1, j, id);
    }
    if (j < n && grid[i][j + 1] == 'X') {
        dfs1(i, j + 1, id);
    }
    if (j > 1 && grid[i][j - 1] == 'X') {
        dfs1(i, j - 1, id);
    }
}


int mindist[51][51];
int mem[51][51];
/*
@param i current i
@param j current j
@param ti target i
@param tj target j
*/
int dfs2(int i, int j) {
    if (mem[i][j] <= 500)
        return mem[i][j];
    mem[i][j] = 500;
    if (grid[i][j] == 'S') {
        // cout << "y" << endl;
        if (i < n) mem[i][j] = min(mem[i][j], dfs2(i + 1, j) + 1);
        if (j < n) mem[i][j] = min(mem[i][j], dfs2(i, j + 1) + 1);
        if (i > 1) mem[i][j] = min(mem[i][j], dfs2(i - 1, j) + 1);
        if (j > 1) mem[i][j] = min(mem[i][j], dfs2(i, j - 1) + 1);
        return mem[i][j];
    }
    return mem[i][j];
}

/*
@param iid island 1's id
@param jid island 2's id
*/
void calcmindist(int iid, int jid) {
    for (pair<int, int> &i : island[iid]) {
        memset(mem, 0x01, sizeof(mem));
        for (pair<int, int> &j : island[jid]) {
            mem[j.first][j.second] = 0;
        }
        if (i.first > 1) mindist[iid][jid] = min(mindist[iid][jid], dfs2(i.first - 1, i.second));
        if (i.second > 1) mindist[iid][jid] = min(mindist[iid][jid], dfs2(i.first, i.second - 1));
        if (i.first < n) mindist[iid][jid] = min(mindist[iid][jid], dfs2(i.first + 1, i.second));
        if (i.second < n) mindist[iid][jid] = min(mindist[iid][jid], dfs2(i.first, i.second + 1));
    }
}

/*
@param num number of islands
*/
void calcmindists(int num) {
    memset(mindist, 0x7f, sizeof(mindist));
    for (int i = 1; i <= num; i++) {
        for (int j = i + 1; j <= num; j++) {
            calcmindist(i, j);
        }
    }
}

bool incl[16];
vector<tuple<int, int, int>> edge;
int main() {
    freopen("island.in", "r", stdin);
    freopen("island.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == 'X') {
                cnt++;
                dfs1(i, j, cnt);
            }
            // if (grid[i][j] < 16)cout << (int)grid[i][j] << ' ';
            // else cout << "- ";
            // cout << grid[i][j] << ' ';
        }
        // cout << endl;
    }
    calcmindists(cnt);
    for (int i = 1; i <= cnt; i++) {
        for (int j = i + 1; j <= cnt; j++) {
            if (mindist[i][j] < 500)edge.push_back(make_tuple(i, j, mindist[i][j]));
        }
    }
    sort(edge.begin(), edge.end(),
        [](const tuple<int, int, int> &t1, const tuple<int, int, int> &t2) {
            return get<2>(t1) < get<2>(t2);
        }
    );
    // for (auto &i : edge) {
    //     cout << get<2>(i) << ' ';
    // }cout << endl;
    memset(incl, 0, sizeof(incl));
    int nincl = 1;
    incl[1] = 1;
    int ans = 0;
    for (auto &i : edge) {
        if (nincl == n) break;
        if (!incl[get<0>(i)] || !incl[get<1>(i)]) {
            nincl++;
            ans += get<2>(i);
            incl[get<0>(i)] = incl[get<1>(i)] = 1;
        }
    }
    cout << ans << endl;
}