#include <bits/stdc++.h>
#define cow(i, j) cows[i + 1][j + 1]
using namespace std;
int n;
bool cows[1003][1003]; // this wont work because we might have to expand beyone 1 tile off of the grid
int solve(int x, int y) {
    // int cnt = cow(x+1,y)+cow(x,y+1)+cow(x-1,y)+cow(x,y-1);
    // if(cnt==3){
    //     ret=1;
    //     if(!cow(x+1,y)){
    //         cow(x+1,y)=1;
    //         ret+=solve(x+1,y);
    //         if(cow(x+1,y+1)) ret+=solve(x+1,y+1);
    //         if(cow(x+1,y-1)) ret+=solve(x+1,y-1);
    //     }else if(!cow(x,y+1)){
    //         cow(x,y+1)=1;
    //         ret+=solve(x,y+1);
    //         if(cow(x+1,y+1)) ret+=solve(x+1,y+1);
    //         if(cow(x-1,y+1)) ret+=solve(x-1,y+1);
    //     }else if(!cow(x-1,y)){
    //         cow(x-1,y)=1;
    //         ret+=solve(x-1,y);
    //         if(cow(x-1,y+1)) ret+=solve(x-1,y+1);
    //         if(cow(x-1,y-1)) ret+=solve(x-1,y-1);
    //     }else{
    //         cow(x,y-1)=1;
    //         ret+=solve(x, y-1);
    //         if(cow(x+1,y-1)) ret+=solve(x+1,y-1);
    //         if(cow(x-1,y-1)) ret+=solve(x-1,y-1);
    //     }
    // }
    // return ret;
}
int main() {
    memset(cows, 0, sizeof(cows));
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        cow[x][y] = 1;
        if (i == n - 1) {
            solve(x, y);
            for (int j = 0; j < n; j)
        }
    }
}