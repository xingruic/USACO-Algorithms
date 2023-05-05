#include<bits/stdc++.h>
using namespace std;
int n;
struct cow{
    int x,y,p;
}cows[201];
bool adj[201][201];
int dist[201][201];
int main(){
    memset(adj,0,sizeof(adj));
    memset(dist,-1,sizeof(dist));
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>cows[i].x>>cows[i].y>>cows[i].p;
        cows[i].p*=cows[i].p;
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            dist[i][j]=dist[j][i]=(cows[i].x-cows[j].x)*(cows[i].x-cows[j].x)+(cows[i].y-cows[j].y)*(cows[i].y-cows[j].y);
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dist[i][j]<cows[i].p) adj[i][j]=1;
        }
    }
    for(int j=1; j<=n; j++){
        for(int i=1; i<=n; i++){
            for(int k=1; k<=n; k++){
                if(adj[i][j]&&adj[j][k]) adj[i][k]=1;
            }
        }
    }
    int mcnt=0;
    for(int i=1; i<=n; i++){
        int cnt=0;
        for(int j=1; j<=n; j++){
            if(adj[i][j]) cnt++;
        }
        mcnt=max(mcnt,cnt);
    }
    cout<<mcnt<<endl;
}