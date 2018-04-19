#include <bits/stdc++.h>
#define clr(v, d)		memset(v, d, sizeof(v))
using namespace std;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int X[8]= {-1,-1,-1,0,0,1,1,1};
int Y[8]= {-1,0,1,-1,1,-1,0,1};
int MAXX=0;
typedef long long         ll;
const ll OO = 1e8;
const int o_o=0;
int T;
int n;
ll b;
struct x{int p;int q;};
map<string,bool>dup;
vector<string>types;
map<string , vector<x> > comp; // type price quality
int globamin=INT_MIN;
int numbers_compontes;
int big_quality=0;
bool f=0;
void bac(int type , int mii , ll sum){
    if(f){return ;}
    if(type>=numbers_compontes && sum<=b ){
            //cout<<type<<" "<<numbers_compontes<<" "<<mii<<" "<<sum<<endl;
        globamin=max(mii,globamin);
        if(big_quality==globamin){
            f=1;

        }
         return ;
    }
    if(sum>b){return ;}
    vector<x>cur;
    cur=comp[types[type]];
    for(int i=0;i<cur.size();i++){
        if(cur[i].p+sum<=b){
            bac(type+1,min(cur[i].q,mii),sum+cur[i].p);
        }
    }
    return ;
}

int main()
{
    cin>>T;
    while(T--){
        dup.clear();
        types.clear();
        comp.clear();
        globamin=INT_MIN;
        numbers_compontes=0;
        big_quality=0;
        f=0;
        cin>>n>>b;
        int j=0;
        for(int i=0;i<n;i++){
            string type,name;
            int q,p;
            cin>>type>>name>>p>>q;
            x c;
            c.p=p;
            c.q=q;
            if(q>big_quality){big_quality=q;}
            comp[type].push_back(c);
            if(!dup[type]){
                types.push_back(type);
                dup[type]=1;
            }

        }

        numbers_compontes=types.size();
        cout<<numbers_compontes<<" "<<big_quality<<endl;
        for(int i=0;i<types.size();i++){
            cout<<types[i]<<endl;
        }
        bac(0,INT_MAX,0);//type 0
        cout<<globamin<<endl;
    }

    return 0;
}
