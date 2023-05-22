#include<bits/stdc++.h>
using namespace std;
int N,M,C;
int a[100001];
int binaryfind(int l=0,int r=2000000000){
    if(l==r) return l;
    int m=(l+r)/2;
    int prev=a[1];
    int cc=0;
    int cnt=1;
    // if(r==7) getchar();
    for(int i=1; i<=N; i++){
        if(a[i]-prev>m||cc==C){
            cnt++;
            prev=a[i];
            cc=0;
        }
        cc++;
    }
    if(cnt>M){
        return binaryfind(m+1,r);
    }else{
        return binaryfind(l,m);
    }
}
int main(){
    freopen("convention.in","r",stdin);
    freopen("convention.out","w",stdout);
    cin>>N>>M>>C;
    for(int i=1; i<=N; i++){
        cin>>a[i];
    }
    sort(a+1,a+1+N);
    cout<<binaryfind()<<endl;
}