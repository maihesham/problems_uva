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
int   temp[MAXX][MAXX];

int main()
{
    string f,s;
    int e=0;
    while(getline(cin,f)&&f[0]!='#'){
        getline(cin,s);
        int n=f.size(),m=s.size();
        for(int i=0;i<max(n,m);i++){
            temp[0][i]=0;
            temp[i][0]=0;
        }
        int maxx = 0;
        for(int i=1; i < n; i++){
            for(int j=1; j < m; j++){
                if(f[i-1] == s[j-1]) {
                    temp[i][j] = temp[i - 1][j - 1] + 1;
                }
                else
                {
                    temp[i][j] =max(temp[i][j-1],temp[i-1][j]);
                }
                if(temp[i][j] > maxx){
                    maxx = temp[i][j];
                }
            }
        }
         e++;
        printf("Case #%d: you can visit at most %d cities.\n",e,maxx);


    }

    return 0;
    }
