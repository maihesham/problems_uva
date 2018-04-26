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
int A[1000+9];
int T[1000+9];
int actualSolution[1000+9];
int si;
string y;
int convert(string y);
void inz(){
    for(int i=0;i<1000+9;i++){
        T[i]=1;
        actualSolution[i] = i;
    }
}
int main()
{
    int z;
    cin>>z;
    getline(cin,y);
    getline(cin,y);
    while(z--){
        si=0;
        inz();
        while(true){
            getline(cin,y);
            if(y[0]=='\0'){break;}
            A[si]=convert(y);
            si++;
        }
        for(int i=1; i <si; i++){
            for(int j=0; j < i; j++){
                if(A[i] > A[j]){
                    if(T[j] + 1 > T[i]){
                        T[i] = T[j] + 1;
                        actualSolution[i] = j;
                    }
                }
            }
        }
         int maxIndex = 0;
        for(int i=0; i < si; i++){
            if(T[i] > T[maxIndex]){
                maxIndex = i;
            }
        }
        printf("Max hits: %d\n",T[maxIndex]);
        int arr[maxIndex+1];
        int ss=0;
        int t = maxIndex;
        int newT = maxIndex;
        do{
            t = newT;
            arr[ss]=A[t];
            ss++;
            newT = actualSolution[t];
        }while(t != newT);
        for(int j=ss-1;j>=0;j--){
            printf("%d\n",arr[j]);
        }
        if(z)
            printf("\n");
    }



    return 0;
    }

int convert(string y){
    istringstream buffer(y);
    int v;
     buffer >> v;
    return v;

    }
