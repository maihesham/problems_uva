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
vector<int>x;
bool f=0;
int part=0;
void convertstringtovector(string t){
    stringstream ss;
     ss << t;
     int el;
     while(ss >> el){
           x.push_back(el);
        }
}
int calculatesum(){
    int sum=0;
    for(int i=0;i<x.size();i++){
        sum+=x[i];
    }
    return sum;
}
bool solve(int index,int sum){
    if(index!=-1){if(index>=x.size()-1){return 0;}}
    if(sum==part){f=1;return 1;}
    solve(index+1,sum+x[index+1]);
    solve(index+1,sum);


}

int main(){
    std::ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    string takeline;
    getline(cin,takeline);
    while(n--){
        string t;
        getline(cin,t);
        x.clear();
        f=0;
         convertstringtovector(t);
         int sum=calculatesum();
         part=sum/2;
        if(sum%2==0){
            solve(-1,0);
        }else if(sum%2!=0){
             cout<<"NO"<<endl;
             continue ;
        }
        if(f==1){
            cout<<"YES"<<endl;
            continue;
        }else if(f==0){
            cout<<"NO"<<endl;
            continue
        }

    }
    return 0;
}
