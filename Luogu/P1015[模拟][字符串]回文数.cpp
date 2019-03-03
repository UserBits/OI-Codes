#include<cstdio>
#include<cstring>
char s[201];
int a[401],top;
inline bool judge()
{
    int t=top/2;
    for (int i=0;i<=t;++i)
        if (a[i]!=a[top-i])
            return true;
    return false;
}
int main()
{
    int n,step=0;
    scanf("%d%s",&n,s);
    top=strlen(s)-1;
    for (int i=0;i<=top;++i){
        if (s[i]>='0'&&s[i]<='9')
            a[top-i]=s[i]-'0';
        else
            a[top-i]=s[i]-55;
	}
    while (judge())
    {
        if (step>30)
            return puts("Impossible!")&0;
        for (int i=0;i<=top;++i)
            if (top-i>=i)
                a[i]+=a[top-i];
            else
                a[i]=a[top-i];
        for (int i=0;i<=top;++i){
            if (a[i]>=n)
                a[i+1]++,a[i]-=n;
		}
        if (a[top+1])
            top++;
        step++;
    }
    printf("STEP=%d\n",step);
    return 0;
}
