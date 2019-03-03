#include<cstdio>
char s[500];
int stk[500],len;
long long pla[500];
inline const int doing(const int l,const int r)
{
    if(s[l]=='R')
        return pla[l]*doing(l+2,pla[l+1])+doing(pla[l+1]+1,r);                                                                                                                //面的部分
    else
    {
        int i,ans=0;
        for(i=l;i<r && s[i]!='R';i++)
        {
            if(s[i]=='F')ans+=pla[i];
            else ans-=pla[i];
        }
        if(i<r)ans+=doing(i,r);
        return ans;
    }
}
inline const int abs(const int x)
{
    if(x>=0)return x;
    else return -x;
}
int main()
{
    char c=getchar();
    int top=-1,i,ans;
    long long x;
    while(c!=EOF)
    {
        if(c=='[')
        {
            stk[++top]=len;
            s[len++]='[';
        }
        else
        if(c==']')
        {
            pla[pla[len]=stk[top]]=len;
            stk[top--]=0;
            s[len++]=']';
        }
        else
        if(c=='B' || c=='F' || c=='R')
        {
            s[len]=c;
            while('0'>c || '9'<c)c=getchar();
            x=0;
            while('0'<=c && c<='9')
            {
                x=x*10+c-'0';
                c=getchar();
            }
            pla[len++]=x;
            continue;
        }
        c=getchar();
    }
    printf("%d\n",abs(doing(0,len)));
    return 0;
}
