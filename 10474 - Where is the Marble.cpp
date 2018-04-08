#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int X[8]= {-1,-1,-1,0,0,1,1,1};
int Y[8]= {-1,0,1,-1,1,-1,0,1};
typedef long long         ll;
const ll OO = 1e8;
const int o_o=0;
int n,q,j=1;

int main(){
    while(true){

        cin>>n>>q;
        if(n==0 && q==0 ){
            break;
        }
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        printf("CASE# %d:\n",j);
        for(int i=0;i<q;i++){
            int x;
            cin>>x;
            int w=-1,s=0,e=n-1,mid;
            while(s < e) {
                int mid = s + (e-s)/2;
                if(arr[mid] < x)
                    s= mid+1;
                else if(arr[mid] > x)
                        e = mid-1;
                else{
                    e  = mid;
                }

                }

            if(arr[s]!=x){
                printf("%d not found\n",x);
            }else{
                printf("%d found at %d\n",x,s+1);
            }
        }
        j++;
    }
    return 0;
}

