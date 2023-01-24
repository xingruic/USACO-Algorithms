#include<bits/stdc++.h>
using namespace std;
int t,n,k;
string cows;
int main(){
    // freopen("ftc.out","w",stdout);
    cin>>t;
    for(int test=0; test<t; test++){
        cin>>n>>k;
        cin>>cows;
        string ans="";
        for(int i=0; i<n; i++){
            ans+='.';
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            if(cows[i]=='G'){
                    ans[min(n-1,i+k)]='G';
                    i+=k*2;
                    cnt++;
            }
        }
        bool again=0;
        for(int i=0; i<n; i++){
            if(cows[i]=='H'){
                bool f=1;
                for(int j=min(n-1,i+k); j>=i; j--){
                    // cout<<cows[j]<<endl;
                    if(ans[j]=='.'){
                        ans[j]='H';
                        i=j+k;
                        cnt++;
                        f=0;
                        break;
                    }
                }
                if(f) again=1;
            }
        }
        if(!again){
            cout<<cnt<<endl<<ans<<endl;
            continue;
        }
        again=0;
        for(int i=n-1; i>=0; i--){
            if(cows[i]=='H'){
                bool f=1;
                for(int j=max(0,i-k); j<=i; j++){
                    // cout<<cows[j]<<endl;
                    if(ans[j]=='.'){
                        ans[j]='H';
                        i=j-k;
                        cnt++;
                        f=0;
                        break;
                    }
                }
                if(f) again=1;
            }
        }
        assert(!again);
        cout<<cnt<<endl<<ans<<endl;
    }
}