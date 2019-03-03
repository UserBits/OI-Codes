#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    string a,b,c,d;
    getline(cin,a);
    getline(cin,b);
    getline(cin,c);
    getline(cin,d);
    int cnt[26]={0},i,maxn=0,j;
    char ch;
    for(i=0;i<a.size();i++)
    {
        int p=(int)a[i]-'A';
        if(p>-1 && p<26)
            cnt[p]++;
    }
    for(i=0;i<b.size();i++)
    {
        int p=(int)b[i]-'A';
        if(p>-1 && p<26)
            cnt[p]++;
    }
    for(i=0;i<c.size();i++)
    {
        int p=(int)c[i]-'A';
        if(p>-1 && p<26)
            cnt[p]++;
    }
    for(i=0;i<d.size();i++)
    {
        int p=(int)d[i]-'A';
        if(p>-1 && p<26)
            cnt[p]++;
    }
    for(i=0;i<26;i++)
    {
        if(cnt[i]>maxn)
            maxn=cnt[i];
    }
    for(i=maxn;i>0;i--)
    {
        for(j=0;j<26;j++)
        {
            if(cnt[j]>=i)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    for(ch='A';ch<'Z';ch++)
    {
        printf("%c ",ch);
    }
    printf("Z\n");
    return 0;
}
