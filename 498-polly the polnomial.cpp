//498 - Polly the Polynomial
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
int n;
vector<ll>coff;
vector<ll>x;
ll  re=0;
vector<ll> convertstringtovector(string t);
int main()
{
    string co,xs;
   while(getline(cin,co)){
     getline(cin,xs);
     coff=convertstringtovector(co);
     x=convertstringtovector(xs);
     for(int j=0;j<x.size();j++){
            ll curentx=x[j];
            ll base=1;
            ll res=0;
           for(int i=coff.size()-1;i>=0;i--){
                res+=(coff[i]*base);
                base=base*curentx;
            }
            if(j)
                putchar(' ');
            printf("%d", res);
     }
     cout<<endl;
     x.clear();
     coff.clear();



   }


return 0;
}
vector<ll> convertstringtovector(string t){
    vector<ll> l;
    stringstream ss;
     ss << t;
     ll el;
     while(ss >> el){
           l.push_back(el);
        }
        return l;
}

