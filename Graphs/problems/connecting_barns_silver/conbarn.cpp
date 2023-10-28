#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int T;
int n,m;
vector<int> adj[100001];
int group[100001];
vector<int> groups[100001];
void dfs(int x,int gid){
    group[x]=gid;
    for(int &i:adj[x]){
        if(!group[i]){
            dfs(i,gid);
        }
    }
}
int mindist(int ga,int gb){
    int mind=0x7fffffff;
    for(int x:groups[ga]){
        int i=distance(lower_bound(groups[gb].begin(),groups[gb].end(),x),groups[gb].begin());
        
    }
}
int main(){
    freopen("conbarn.in","r",stdin);
    freopen("conbarn.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1; i<=n; i++) adj[i].clear(),groups[i].clear();
        int x,y;
        for(int i=1; i<=m; i++){
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        memset(group,0,sizeof(group));
        int cnt=0;
        for(int i=1; i<=n; i++){
            if(!group[i]){
                cnt++;
                dfs(i,cnt);
            }
        } // now cnt = the number of groups
        for(int i=1; i<=n; i++){
            groups[group[i]].push_back(i);
        }
        for(int i=1; i<=n; i++) cout<<(int)group[i]<<' ';
        cout<<endl;
        
    }
}