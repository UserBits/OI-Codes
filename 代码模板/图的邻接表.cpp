#include <cstdio>
using namespace std;
int size=0;
struct Edge
{
	int now,next;
}edge[20005];
int head[10005];
void Insert(int x,int y){
	size++;
	edge[size].now=y;
	edge[size].next=head[x];
	head[x]=size;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
    {
    	int x,y;
    	scanf("%d%d",&x,&y);
    	Insert(x,y);
    	Insert(y,x);
    }
    for(int i=1;i<n;i++)
    {
    	printf(" %d -> ",i);
    	for(int j=head[i];j;j=edge[j].next)
			printf(" %d , ",edge[j].now);
    	putchar('\n');
	}
}
