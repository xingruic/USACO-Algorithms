#include<bits/stdc++.h>
using namespace std;
int b,s,c;
int pb,ps,pc;
long long coins;
int nb=0,ns=0,nc=0;
inline long long price(int num){
    return max((num*nb-b)*pb,0)+max((num*ns-s)*ps,0)+max((num*nc-c)*pc,0);
}
int main(){
    string burger;
    cin>>burger;
    for(char c:burger){
        if(c=='B') nb++;
        if(c=='S') ns++;
        if(c=='C') nc++;
    }
    cin>>b>>s>>c>>pb>>ps>>pc>>coins;

    int max_input=0;
    if(ns>0) max_input=max(max_input,s/ns);
    if(nb>0) max_input=max(max_input,b/nb);
    if(nc>0) max_input=max(max_input,c/nc);
    // cout<<max_input<<endl;
    long long p=price(max_input+1);
    if(p>coins){
        for(int i=max_input;i>=0;i--){
            if(price(i)<coins){
                cout<<i<<endl;
                exit(0);
            }
        }
    }
    coins-=p;
    // cout<<coins<<endl;
    // cout<<nb*pb+nc*pc+ns*ps<<endl;
    cout<<max_input+1+coins/(nb*pb+nc*pc+ns*ps)<<endl;
}