#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
vector<vector<int>> matrixBlockSum(vector<vector<int>> mat, int k) {
    vector<vector<int>> psum;
    psum.resize(mat.size());
    for (vector<int> &i : psum) {
        i.resize(mat[0].size());
    }
    psum[0][0] = mat[0][0];
    for (int i = 1; i < mat.size(); i++) {
        psum[i][0] = psum[i - 1][0] + mat[i][0];
    }
    for (int j = 1; j < mat[0].size(); j++) {
        psum[0][j] = psum[0][j - 1] + mat[0][j];
    }
    for (int i = 1; i < mat.size(); i++) {
        for (int j = 1; j < mat[i].size(); j++) {
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + mat[i][j];
        }
    }
    // for (vector<int> &i : psum) {
    //     for (int &j : i) {
    //         cout << j << '\t';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            int r1, c1, r2, c2;
            r1 = max(i - k, 0);
            c1 = max(j - k, 0);
            r2 = min(i + k, (int)psum.size() - 1);
            c2 = min(j + k, (int)psum[i].size() - 1);
            int p22 = psum[r2][c2],
                p12, p21, p11 = -1;
            if (r1 == 0) {
                p12 = p11 = 0;
            } else {
                p12 = psum[r1 - 1][c2];
            }
            if (c1 == 0) {
                p21 = p11 = 0;
            } else {
                p21 = psum[r2][c1 - 1];
            }
            if (p11 == -1) p11 = psum[r1 - 1][c1 - 1];
            mat[i][j] = p22 - p12 - p21 + p11;
        }
    }
    // for (vector<int> &i : mat) {
    //     for (int &j : i) {
    //         cout << j << '\t';
    //     }
    //     cout << endl;
    // }
    return mat;
}
int main() {
    vector<vector<int>> mat = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };
    matrixBlockSum(mat, 1);
}