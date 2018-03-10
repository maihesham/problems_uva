#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include<cmath>
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <limits>
using namespace std;
#define siz(v)	((int)((v).size())) //get size of vector
#define inz(v, d) memset(v, d, sizeof(v)) // inizalize vector by d
#define repvector(i, v) for(int i=0;i<siz(v);++i)  //loop on vevtor from i to v.size
#define repincr(i, j, n) for(int i=(j);i<(int)(n);++i)
#define repdec(i, n)	for(int i=n-1;i>=0;--i)
typedef long long         ll;
const ll OO = 1e8;
const int o_o=0;
//double  EPS=numeric_limits<double>::epsilon();
const double EPS = (1e-7);
int arr[5];
bool fa=0;
bool vis[5];
void DFS(int index,int sum){
    if(index>=5){
            if(sum==23){
                 fa=1;
                 return ;
            }
          return ;
    }
    for(int i=0;i<5;i++){
        if(vis[i]==0){
                vis[i]=1;
            DFS(index+1,sum+arr[i]);
            DFS(index+1,sum-arr[i]);
            DFS(index+1,sum*arr[i]);
            vis[i]=0;
        }
    }
    return ;

}

int main(){
    std::ios_base::sync_with_stdio(0);
    while(cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4]){
       if(arr[0]==0&&arr[1]==0&&arr[2]==0&&arr[3]==0&&arr[4]==0){return 0;}
       fa=0;
       for(int i=0;i<5;i++){
        vis[i]=0;
       }
       for(int i=0;i<5;i++){
          vis[i]=1;
           DFS(1,arr[i]);
           if(fa){
            cout<<"Possible"<<endl;
            break;
           }
       vis[i]=0;
       }
       if(fa==0){cout<<"Impossible"<<endl;}
    }
    return 0;
}
