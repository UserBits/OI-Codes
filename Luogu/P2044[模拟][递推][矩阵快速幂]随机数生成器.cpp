#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

const int N = 2;
typedef long long ll;
ll mod;

struct node{
    ll a[3][3];
    node(){
        memset(a, 0, sizeof(a));
    }
};

inline ll slow_mul(ll x, ll y){
    ll r = 0;
    while(y){
        if(y & 1)
            r = (r + x) % mod;
        x = (x << 1) % mod;
        y >>= 1;
    }
    return r;
} 

inline node multi(node p, node q){
    node tp;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= N; k++)
                tp.a[i][j] = (tp.a[i][j] + slow_mul(p.a[i][k], q.a[k][j])) % mod;
        }
    }
    return tp;
}

inline node ksm(node x, ll y){
    node r;
    for(int i = 1; i <= N; i++)
        r.a[i][i] = 1;
    while(y){
        if(y & 1)
            r = multi(r, x);
        x = multi(x, x);
        y >>= 1;
    }
    return r;
}

int main(){
    ll a, c, x0, n, g;
    scanf("%lld%lld%lld%lld%lld%lld", &mod, &a, &c, &x0, &n, &g);
    node x, y;
    x.a[1][1] = a;
    x.a[2][1] = c;
    x.a[2][2] = 1;
    x = ksm(x, n);
    y.a[1][1] = x0;
    y.a[1][2] = 1;
    node ans = multi(y, x);
    //矩阵乘法不满足交换律
    printf("%lld\n", ans.a[1][1] % g);
    //system("pause");
    return 0;
}