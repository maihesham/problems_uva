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
int N,si;
vector<int> tracks;
int golbasum=INT_MIN;
vector<int>re;
bool f=0;
bool solve(int index,int sum , vector<int> p){
    if(index!=-1){if(index>=tracks.size()){return 0;}}
    if(sum>golbasum&&sum<=N){
        golbasum=sum;
        re=p;
    }
    if(sum==N){
         return 1;
    }
    p.push_back(tracks[index+1]);
    solve(index+1,sum+tracks[index+1],p);
    p.erase(p.begin()+p.size()-1);
    solve(index+1,sum,p);


}

int main(){
    std::ios_base::sync_with_stdio(0);

    while(cin>>N>>si){
       for(int i=0;i<si;i++){
        int y;
        cin>>y;
        tracks.push_back(y);
       }
       vector<int>v;
       solve(-1,0,v);
       for(int i=0;i<re.size();i++){
        cout<<re[i]<<" ";
       }
       cout<<"sum:"<<golbasum<<endl;
       re.clear();
       tracks.clear();
       v.clear();
       golbasum=INT_MIN;
       N=si=0;
       f=0;

    }
    return 0;
}
