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
int n=1;
int main()
{
    while(1){
        scanf("%d",&n);
        if(n==-1){
            return 0;
        }
         if(n==0){
        	cout<<0<<" "<<1<<endl;
        	continue;
        }
       ll  m=1;
        ll f=1;
        for(ll i=2;i<=n;i++){
           ll tempf=f,tempm=m;
            m=m+tempf;
            f=1;
            f=f+tempm;

        }
       
        cout<<m<<" "<<f+m<<endl;

    }


     return 0;
}

