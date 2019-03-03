#include <cstdio>
#include <cstdlib>
using namespace std;
long long StringLength[10005];
inline void OutputChar(char out)
{
    putchar(out);
	exit(0);
}
void WorkFunction(int n,int TempChar)
{
    if(n==1 || n==StringLength[TempChar-1]+1)
        OutputChar('m');
	else if(n<=3 || (n>StringLength[TempChar-1] && n<=StringLength[TempChar-1]))
        OutputChar('o');
	else if(n>StringLength[TempChar-1]+TempChar+3)
	{
        n-=StringLength[TempChar-1]+TempChar+3;
        TempChar--;
        WorkFunction(n,TempChar);
    }
	else
	{
        TempChar--;
        WorkFunction(n,TempChar);
    }
}
int main()
{
    int n,i=1;
    scanf("%d",&n);
    StringLength[0]=3;
    for(;StringLength[i-1]<n;i++)
        StringLength[i]=StringLength[i-1]*2+i+3;
    WorkFunction(n,i-1);
    return 0;
}

