#include <bits/stdc++.h>
#define clr(v, d)		memset(v, d, sizeof(v))
using namespace std;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int X[8]= {-1,-1,-1,0,0,1,1,1};
int Y[8]= {-1,0,1,-1,1,-1,0,1};
const int MAXX=100+9;
typedef long long         ll;
const ll OO = 1e8;
const int o_o=0;
int T,n;
struct p{
int pn1;int pn2;double distane; double distane2=0.0;};
vector<p> q;
int parent[100+9];
double xp[100+9];
double yp[100+9];
void inzaltion(int m){
    for(int i=0;i<m;i++){
        parent[i]=i;
    }
}
int find_parent(int s){
    if(parent[s]!=s){
        parent[s]=find_parent(parent[s]);
    }
    return parent[s];
}
//uses union by rank
void unoin_parent(int s,int d){
    parent[s]=find_parent(d);
}
bool detect_cycle(int x, int y){

          int p1=find_parent(x);
          int p2=find_parent(y);
          if(p1==p2){
            return 1;
          }
          unoin_parent(p1,p2);
          return 0;


}
bool com(const struct p &x1, const struct p &x2){
    return x1.distane2<x2.distane2;
}
double value_of_min_spanning_tree=0.0;
void  KruskalMST(){
    for(int i=0;i<q.size();i++){
          bool f=detect_cycle(q[i].pn1,q[i].pn2);

          if(f==0){
                // cout<<q[i].pn1<<" "<<q[i].pn2<<q[i].distane<<endl;
                 value_of_min_spanning_tree+=q[i].distane2;
          }
    }

}
int main()
{
    cin>>T;
    while(T--){
        cin>>n;
        q.clear();
        value_of_min_spanning_tree=0;
        inzaltion(n);
        for(int i=0;i<n;i++){
            cin>>xp[i]>>yp[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                p l;
                l.pn1=i;
                l.pn2=j;
                l.distane=((xp[i]-xp[j])*(xp[i]-xp[j])) + ((yp[i]-yp[j])*(yp[i]-yp[j]));
                l.distane2=sqrt(l.distane);
                q.push_back(l);
            }
        }
        sort(q.begin(),q.end(),com);
        KruskalMST();
        cout<<fixed<<setprecision(2)<<value_of_min_spanning_tree<<endl;
        if(T){
            cout<<endl;
        }

    }




     return 0;
}

