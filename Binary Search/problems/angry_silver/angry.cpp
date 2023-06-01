#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[50001];
int search(int l=0,int r=1000000000){
    if(l==r) return l;
    int m=(l+r)/2,d=m*2;
    int cows=k-1;
    int start=a[1];
    for(int i=1; i<=n; i++){
        if(a[i]-start>d){
            cows--;
            start=a[i];
        }
        if(cows<0) break;
    }
    if(cows<0) return search(m+1,r);
    else return search(l,m);
}
int main(){
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    cout<<search()<<endl;
}