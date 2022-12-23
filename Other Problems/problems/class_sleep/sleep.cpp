#include<bits/stdc++.h>
using namespace std;
int t;
int n;
vector<int> a;
int combine(vector<int> v){
    if(v.size()==2) return v[0]!=v[1];
    int ret=0x7fffffff;
    for(auto i=++v.begin(); i!=v.end(); i++){
        int x=*(--i);
        *(++i)+=x;
        ret=min(ret,combine(v));
        *i-=x;
    }
    return ret;
}
int main(){
    cin>>t;
    for(int test=0; test<t; test++){
        cin>>n;
        for(int i=1; i<=n; i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
    }
    combine(a);
}