#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v = { 0,1,2,3,4,5 };
    vector<int> v2;
    auto j = v.begin();
    j++;
    cout << *j << endl;
    v.erase(j);
    v2.emplace(j, 10);
    cout << *j << endl;
}