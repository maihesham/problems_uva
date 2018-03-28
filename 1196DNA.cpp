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
int t , n, k;
string dNA;
set<string > res;
char Sd[]={'A','C','G','T'};
void GET_Dnaa(int indx,int nChange,string d){
    if(nChange==k){
        res.insert(d);
        return ;
    }
    if(indx>=dNA.size()){return ;}

   string h=d;
   h[indx]=Sd[0];
   GET_Dnaa(indx+1,nChange+1,h);
   string h1=d;
   h1[indx]=Sd[1];
   GET_Dnaa(indx+1,nChange+1,h1);
   string h2=d;
   h2[indx]=Sd[2];
   GET_Dnaa(indx+1,nChange+1,h2);
   string h3=d;
   h3[indx]=Sd[3];
   GET_Dnaa(indx+1,nChange+1,h3);
   GET_Dnaa(indx+1,nChange,d);
   return ;

}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>k;
        res.clear();
        cin>>dNA;
        GET_Dnaa(0,0,dNA);
        cout<<res.size()<<endl;
        for (std::set<string>::iterator it=res.begin(); it!=res.end(); ++it)
                         std::cout <<  *it<<endl;;
    }
return 0;
}
