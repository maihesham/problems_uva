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
int n,j=1;
string fr="CALL FORWARDING OUTPUT",las="END OF OUTPUT";
vector<vector<int> > p;
int cycle=0;
int  slove(int numcalles,int source,int tim,int newtarget){
    if(numcalles>0&&source==newtarget){
        newtarget=9999;
        cycle=1;
        return newtarget;
    }
   for(int i=0;i<p[newtarget].size();i+=3){
          if(tim>=p[newtarget][i]&&tim<=p[newtarget][i+1]+p[newtarget][i]){
            newtarget= p[newtarget][i+2];
            int r=slove(numcalles+1,source,tim,newtarget);
            if(r!=9999){
                newtarget=r;
                break;
            }else{
                newtarget=r;
            }
        }
   }
   return newtarget;
}
int main() {

   cin>>n;
   cout<<fr<<endl;
   while(n--){
     p.clear();
     p.resize(10000);
    int s,tim,duration,target;
    while(cin>>s){
        if(s==0){break;}
        cin>>tim>>duration>>target;
        p[s].push_back(tim);
        p[s].push_back(duration);
        p[s].push_back(target);

    }
    int t,sou;
    cout<<"SYSTEM "<<j<<endl;
    j++;
    while(cin>>t){
        if(t==9000){
            break;
        }
        cin>>sou;
        printf("AT %04d CALL TO %04d RINGS %04d\n", t, sou, slove(0,sou,t,sou));
    }
    //AT 0050 CALL TO 1111 RINGS 1111

   }
   cout<<las<<endl;


    return 0;
}
