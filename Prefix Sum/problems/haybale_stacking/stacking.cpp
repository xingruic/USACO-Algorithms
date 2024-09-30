#include<iostream>
#include<map>
using namespace std;
int n,k;
map<int,int> instr; // note: for key=i, apply the val between hay bales i and i-1.
map<short,int> cnt;
int main(){
    freopen("stacking.in","r",stdin);
    freopen("stacking.out","w",stdout);
    cin>>n>>k;
    {
        int a,b;
        for(int i=1; i<=k; i++){
            cin>>a>>b;
            if(instr.find(a)!=instr.end()) instr[a]++;
            else instr[a]=1;
            if(instr.find(b+1)!=instr.end()) instr[b+1]--;
            else instr[b+1]=-1;
            // cout<<a<<' '<<b<<' '<<b+1<<endl;
            // cout<<instr[a]<<' '<<instr[b+1]<<endl<<endl;
        }
        // cout<<endl;
    }
    int curr=0;
    int prev_loc=1;
    int tot=0;
    for(const auto &p:instr){
        if(p.second!=0){
            if(cnt.find(curr)!=cnt.end()){
                cnt[curr]+=p.first-prev_loc;
            }else{
                cnt[curr]=p.first-prev_loc;
            }
            prev_loc=p.first;
            curr+=p.second;
        }
    }
    if(cnt.find(0)!=cnt.end()){
        cnt[0]+=n+1-prev_loc;
    }else{
        cnt[0]=n+1-prev_loc;
    }
    int N=n; // N is always odd, according to problem statement
    for(const auto &p:cnt){
        N-=p.second;
        if(N<=n/2){
            cout<<p.first<<endl;
            break;
        }
    }
}