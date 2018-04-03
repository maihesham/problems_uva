#include <bits/stdc++.h>
using namespace std;
typedef long long         ll;
const ll OO = 1e8;
const int o_o=0;
#define Max 300000
int pox[Max];
int poy[Max];
int main(){
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
   while(T>0) {
            for(int i=0;i<T;i++){
                cin>>pox[i]>>poy[i];
            }
            int c=T/2;
            int stan=0,ollie=0;
            for(int i=0;i<T;i++){
                if(pox[i]>pox[c]&&poy[i]>poy[c]){
                    stan++;
                }else if(pox[i]<pox[c]&&poy[i]<poy[c]){
                    stan++;
                }else if(pox[i]<pox[c]&&poy[i]>poy[c]){
                    ollie++;
                }else if(pox[i]>pox[c]&&poy[i]<poy[c]){
                    ollie++;
                }
            }
            cout<<stan<<" "<<ollie<<endl;
            cin>>T;
            stan=ollie=0;
            for(int i=0;i<Max;i++){
                pox[i]=poy[i]=-1;
            }
       }



return 0;
}
