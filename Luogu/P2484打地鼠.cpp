#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int m,n,a[100][100]= {0},c[101][101]= {0},p[101][101]= {0},sum=0;

int main() {
    cin >> m >> n;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++) {
            cin >> a[i][j];
            sum+=a[i][j];
        }
    c[0][0]=a[0][0];
    for(int i=1; i<m; i++)
        c[i][0]=a[i][0]-a[i-1][0];
    for(int i=1; i<n; i++)
        c[0][i]=a[0][i]-a[0][i-1];
    for(int i=1; i<m; i++)
        for(int j=1; j<n; j++)
            c[i][j]=a[i][j]+a[i-1][j-1]-a[i-1][j]-a[i][j-1];
    int ans=1;
    for(int R=m; R>=1; R--)
        for(int C=n; C>=1; C--) {
            int ret=R*C;
            if(sum%ret!=0||ret<=ans)continue;
            bool able=true;
            memcpy(p,c,sizeof c);
            for(int i=0; i<m; i++) {
                for(int j=0; j<n; j++) {
                    if(p[i][j]<0) {
                        able=false;
                        break;
                    }
                    if(p[i][j]==0)continue;
                    if(i+R>m||j+C>n) {
                        able=false;
                        break;
                    }
                    p[i][j+C]+=p[i][j];
                    p[i+R][j]+=p[i][j];
                    p[i+R][j+C]-=p[i][j];
                }
            }
            if(!able)continue;
            ans=max(ans,ret);
        }
    cout << (sum/ans) << endl;
    return 0;
}
