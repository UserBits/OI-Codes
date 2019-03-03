#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=510;
int A[MAXN],B[MAXN],C[MAXN],Ans[MAXN],Len_A,Len_B,Len_Ans;
void READ(int *A,int &Len)
{
    string cur;
    cin>>cur;
    Len=cur.length();
    for(int i=0;i<Len;i++)
        A[i]=cur[i]-48;
    reverse(A,A+Len);
}
int main()
{
    READ(A,Len_A);
    READ(B,Len_B);
    Len_Ans=max(Len_A,Len_B);
    for(int i=0;i<=Len_Ans;i++)
    {
        Ans[i]=A[i]+B[i]+C[i];
        if(Ans[i]>9)
        {
            C[i+1]=Ans[i]/10;
            Ans[i]-=10;
        }
    }
    while(Ans[Len_Ans]>0)
        Len_Ans++;
    for(int i=Len_Ans-1;i>=0;i--)
        cout<<Ans[i];
    return 0;
}
