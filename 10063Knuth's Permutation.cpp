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
string m;
void  get_prementation( int next, string pr){
    if(pr.size()==m.size()){
        cout<<pr<<endl;
        return ;
    }
    if(next>pr.size()){return ;}
    string z="";
    string x="";
    z+=m[next];
    z+=pr;
   // cout<<pr.size()<<" "<<pr<< " "<<z<<endl;
   get_prementation( next+1,z);
    for(int j=0;j<pr.size();j++){
        x+=pr[j];
        z="";
        z+=x;
        z+=m[next];
        z+=pr.substr(j+1,pr.size());
        // cout<<pr.size()<<" "<<pr<< " "<<z<<" "<<m[next]<<endl;
         get_prementation( next+1,z);
    }
    return ;

}
int main(){
   bool  flag = 1;
    while(getline(cin,m)) {
        if(!flag)
            puts("");
        flag = 0;
        string x="";
       x+=m[0];
       get_prementation(1,x);

    }

    return 0;
}

