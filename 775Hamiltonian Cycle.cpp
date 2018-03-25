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
const int MAX=256+9;
bool visted[MAX][MAX];
bool found=0;
vector<vector< int > > G;
int n;
vector<int> Cycle;
bool C[MAX];
void inzaltion(){
    G.clear();
    Cycle.clear();
    found=0;
    for(int i=0;i<MAX;i++){
            C[i]=0;
        for(int j=0;j<MAX;j++){
            visted[i][j]=0;
        }
    }
}
void Hamiltonian_Cycle(int V , int M){
    if(found==1){return ;}
    if(M==n&& Cycle[Cycle.size()-1]==1&&Cycle.size()==n&& found==0){
            cout<<1<<" ";
            for(int i=0;i<Cycle.size();i++){
                cout<<Cycle[i];
                if(i+1<Cycle.size()){
                    cout<<" ";
                }
            }
           cout<<endl;
           found=1;
           return ;
    }else if( Cycle.size()> 0 && Cycle[Cycle.size()-1]==1 &&M!= n && Cycle.size()!=n ){
                return;
    }
    for(int i=0;i<G[V].size();i++){
        int j=G[V][i];
        if(!visted[V][j] && !C[j]){
            visted[V][j]=1;
            if(V!=1&&j!=1){
                visted[j][V]=1;
            }
            C[j]=1;
            Cycle.push_back(j);
            Hamiltonian_Cycle(j,M+1);
            visted[V][j]=0;
            if(V!=1&&j!=1){
                visted[j][V]=0;
            }
            C[j]=0;
            Cycle.pop_back();

          }

    }


    return;
}
/*
          */
int main(){
    while(cin>>n){
        inzaltion();
        G.resize(MAX*MAX);
        vector<int> vec;
        if(n==1){
            int x;
            string y;
            cin>>x>>y;
            cout<<"N"<<endl;
            continue;
        }
        while(true){
             string x,y;
             cin>>x;
             if(x=="%"){break;}
             cin>>y;
             int so=atoi( x.c_str() );
             int dis=atoi( y.c_str() );
            G[so].push_back(dis);
            G[dis].push_back(so);
            vec.push_back(so);
            vec.push_back(dis);
        }
        Hamiltonian_Cycle(1,0);
        if(!found){
            cout<<"N"<<endl;
        }
    }

    return 0;
}

