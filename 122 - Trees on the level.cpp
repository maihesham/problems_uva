/*
author : mai hesham 
Accepted 
*/
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=58
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
double  EPS=numeric_limits<double>::epsilon();
int countnumber=0; // number of nodes taken as input 
//take input from user  and count number of input
vector<int>res; // nodes in tree in BFS order
// onenode have visted or not ,  number , postion on tree 
struct onenode{
    int num;
    string pos="";
    bool visted=0;
};
vector<onenode>tree; // vector of node take as input 
void inzlition(){
    countnumber=0;
    res.clear();
    tree.clear();
}
bool BFS(){
    string em="ROOT";int node=-1;
    for(int i=0;i<tree.size();i++){
        if(tree[i].pos==em){
            node=tree[i].num;
            tree[i].visted=1;
            break;
        }
    }
    if(node==-1){
        //cout<<"not found root"<<endl;
        return 0;
    }else{
        res.push_back(node);
        countnumber--;
        queue<string>q;
        string t="L";
        string z="R";
        q.push(t);
        q.push(z);
      //  cout<<"found root size of ququ"<<q.size()<<endl;
        while(1){
            if(q.size()==0){break;}
            if(countnumber<=0){break;}
            string x=q.front();
            q.pop();
            int y=-1;
            for(int i=0;i<tree.size();i++){
                if(tree[i].pos==x&&tree[i].visted==0){
                    tree[i].visted=1;
                    y=tree[i].num;
                    break;
                }
            }
         //   cout<<"postion is "<<x<<" "<<y<<" # of nodes now is "<<countnumber<<endl;
         //   cout<<q.size()<<endl;
            if(y==-1){
                continue;
            }else{
                res.push_back(y);
                countnumber--;
                string x1=x+'L';
                string x2=x+'R';
                q.push(x1);
                q.push(x2);
            }



        }

    }
    if(countnumber>0){return 0;}
    return 1;
}
int converttoint(string nu){
    return  atoi(nu.c_str());
}
void  fullmap(string s){
    string nu="",pos="";int j=0;
    for(int i=1;i<s.size();i++){
        if(s[i]==','){j=i;break;}
        nu+=s[i];
    }
    for(int y=j+1;y<s.size();y++){
        if(s[y]==')'){break;}
        pos+=s[y];
    }
    if(pos==""){// (5,) => name postion by root 
        pos="ROOT";
    }
    int c=converttoint(nu);
    onenode i;
    i.num=c;
    i.pos=pos;
    i.visted=0;
    tree.push_back(i);
}
int main(){
    std::ios_base::sync_with_stdio(0);
    string s;
    //take input from user
    while(cin>>s){
        //s==() end of input     
        if(s=="()"){
               // call BFS to create tree
               bool f=BFS();
               // if # of nodes >0 or size of array is zero or function return  0  so this tree not complete 
               if(countnumber>0 || res.size()==0|| f==0){
                   cout<<"not complete"<<endl;
                 }
                 // if # of nodes = 0 && f== 1 so print result (tree in BFS order)
               else if(countnumber==0 ){
                        for(int i=0;i<res.size();i++){
                                cout<<res[i];
                                if(i+1!=res.size()){
                                    cout<<" ";
                                }
                        }
                        cout<<endl;
                }
                inzlition(); // delete every thing to take new input 
        }else{
           fullmap(s); // make input valid (4,L) => number and postion 
           countnumber++; // count number of nodes 
        }



    }


}