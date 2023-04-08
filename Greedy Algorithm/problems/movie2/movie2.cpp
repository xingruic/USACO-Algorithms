#include<bits/stdc++.h>
using namespace std;
int n,k;
pair<int,int> movies[200001];
bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}
int main(){
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>movies[i].first>>movies[i].second;
    }
    sort(movies+1,movies+n+1,cmp);
    int cnt=k;
    for(int i=1; i<=n; i++){
        
    }
}