#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int X[8]= {-1,-1,-1,0,0,1,1,1};
int Y[8]= {-1,0,1,-1,1,-1,0,1};
const int MAXX=500+9;
typedef long long         ll;
const ll OO = 1e8;
const int o_o=0;
int T,s,d;
int main(){
   cin>>T;
   while(T--){
    cin>>s>>d;
    if(d>s){
        printf("impossible\n");
        continue;
    }else{
        int rem=s-d;
        if(rem<0){rem=rem*-1;}
        int x=rem/2;
        int y=s-x;
        if(x<0){x=x*-1;}
        if(y<0){y=y*-1;}
        if(abs(x-y)==d &&x+y==s){
            printf("%d %d\n",max(x,y),min(x,y));
        }else{
            printf("impossible\n");
        }
    }
   }
return 0;}
