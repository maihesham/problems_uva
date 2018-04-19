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
int m,n,k;
vector< vector <int > > gr;
vector<int>l;
int colr[100+9];
bool checkcan(int i){
    for(int j=0;j<gr[i].size();j++){
        if(colr[gr[i][j]]==-1 ||gr[i][j] == i ){return 0;}
    }
    return 1;
}
vector<int> ma;
void DFS(int curent){
    if(ma.size()>l.size()){
        l=ma;
    }
    if (curent>n)
		return ;
    int v=n-curent;	
    if(l.size()>=v+curent){
        return ;
    }	
		
    for(int i = curent; i <= n; ++i)
	{
		if (checkcan(i))	// switch to black
		{	// do...rec...undo
			colr[i] = -1;
			ma.push_back(i);

			DFS(i+1);

			ma.pop_back();
			colr[i] = 1;
		}
	}
    return ;
}
int main()
{
    cin>>m;
    while(m--){
        cin>>n>>k;
        gr.resize(n*k);
        for(int i=0;i<k;i++){
            int x,y;
            cin>>x>>y;
            gr[x].push_back(y);
            gr[y].push_back(x);
        }
            DFS(1);
            cout<<l.size()<<endl;
            for(int i=0;i<l.size();i++){
                cout<<l[i];
                if(i+1<l.size()){
                    cout<<" ";
                }
            }
            cout<<endl;
          gr.clear();
          l.clear();
          ma.clear();
          clr(colr,0);


    }
    return 0;
}
