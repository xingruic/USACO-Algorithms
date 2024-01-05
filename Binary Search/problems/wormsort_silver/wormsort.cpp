#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=10e5;
int n,m;
int p[maxn];
struct tunnel{
    int a,b,w;
}tun[maxn];
int main(){
    freopen("wormsort.in","r",stdin);
    freopen("wormsort.out","w",stdout);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>p[i];
    }
    for(int i=0; i<m; i++){
        cin>>tun[i].a>>tun[i].b>>tun[i].w;
    }
    
}