#include <bits/stdc++.h>
using namespace std;
int nodetoint(string n) {
    int res = 0;
    for (int i = 0; i < n.size(); i++) {
        res += (n[i] - 'a' + 1) * pow(26, n.size() - i - 1);
    }
    return res;
}
void printdistance(vector<vector<int>> graph, string nodes[2]) {
    int x = nodetoint(nodes[0]) - 1, y = nodetoint(nodes[1]) - 1;
    cerr << x << ' ' << y << endl;
}
int main() {
    freopen("input.txt", "r", stdin);
    int n;
    vector<vector<int>> graph(n, vector<int>(n));
    string nodes[2];
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    cin >> nodes[0] >> nodes[1];
    printdistance(graph, nodes);
}