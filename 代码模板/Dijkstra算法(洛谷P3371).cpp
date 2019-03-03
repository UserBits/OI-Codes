#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;
const int N=10005,M=500005;
struct edge{
    int node,next,val;
}Edge[M];
int Head[N],Dis[N],n,tot;
bool v[N];
struct qNode{//���ȶ��д洢�ڵ�
    int key,len;
    //key:�ڵ���
    //len:��Դ�㵽key�����·
    friend bool operator < (qNode x, qNode y){
        return x.len>y.len;
    }
};

void Add(int x,int y,int l){
    tot++;
    Edge[tot].node=y;
    Edge[tot].next=Head[x];
    Edge[tot].val=l;
    Head[x]=tot;
}

void Dijkstra(int Src){ //Src:Դ��
//Dijkstra���Ż��㷨
    for(int i=1;i<=n;i++)
        Dis[i]=1e9+1;
    Dis[Src]=0;
    priority_queue<qNode> q;
    q.push((qNode){Src,0});
    qNode r;
    while(!q.empty()){
        r=q.top();
        q.pop();
        if(!v[r.key]){ //ǧ������v[r.key]Ϊ1ʱcontinue!!!!!!
        	v[r.key]=1;//ֻ���ڴ˴�����ѷ���
        	for(int k=Head[r.key];k;k=Edge[k].next){
            	if(!v[Edge[k].node] && Dis[r.key]+Edge[k].val<Dis[Edge[k].node]){
                	Dis[Edge[k].node]=Dis[r.key]+Edge[k].val;
                	q.push((qNode){Edge[k].node,Dis[Edge[k].node]});
            	}
        	}
        }
    }
}

inline void qr(int &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}

int main(){
    int m,s,x,y,l;
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++){
        qr(x);  qr(y);  qr(l);
        Add(x,y,l);
    }
    Dijkstra(s);
    for(int i=1;i<=n;i++){
        if(Dis[i]<=1e9)
            printf("%d ",Dis[i]);
        else
            printf("2147483647 ");
    }
    //system("pause");
    return 0;
}
