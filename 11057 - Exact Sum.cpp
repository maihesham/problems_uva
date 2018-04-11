#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int X[8]= {-1,-1,-1,0,0,1,1,1};
int Y[8]= {-1,0,1,-1,1,-1,0,1};
typedef long long         ll;
const ll OO = 1e8;
const int o_o=0;
int n,m;
int books[10000+9];
void  solve(){
//	cout<<"N "<<n<<" M"<<m<<endl;
    int r1,r2;
    for(int i=0;i<n && books[i]<=m;i++){
        int x=m-books[i];
        int s=i+1,e=n-1;
        while(s <= e) {
                int mid = s + (e-s)/2;
                if(books[mid] < x){s= mid+1;}
                else if(books[mid] > x){e = mid-1;}
                else if(books[mid]==x){
                    r1=books[i];
                    r2=x;
                       // cout<<" \n lol "<<r1<<" "<<r2<<endl;

                    break;
                }
        }
    }
        printf("%d and %d.\n", min(r1,r2), max(r1,r2));


}
int main(){
       while(scanf("%d", &n) != EOF){
        for(int i=0;i<n;i++){
            cin>>books[i];
        }
        cin>>m;
        sort(books,books+n);
        printf("Peter should buy books whose prices are ");
        solve();
        putchar('\n');
        for(int i=0;i<10000+9;i++){
            books[i]=0;
        }
        n=m=0;
    }
    

    return 0;
}

