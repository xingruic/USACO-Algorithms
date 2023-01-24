#include<bits/stdc++.h>
using namespace std;
long long n;
long long c[100001];
int main(){
    // freopen("cowllege.in","r",stdin);
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    c[0]=-1;
    cin>>n;
    int cmin=0x7fffffff,cmax=0;
    for(int i=1; i<=n; i++){
        cin>>c[i];
    }
    sort(c+1,c+n+1);
    long long ans=0,tuit=0;
    for(int i=1; i<=n; i++){
        if(c[i]!=c[i-1]){
            if((n+1-i)*c[i]>ans){
                ans=(n+1-i)*c[i], tuit=c[i];
            }
        }
    }
    cout<<ans<<' '<<tuit<<endl;
}