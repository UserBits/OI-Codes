#include<iostream>
using namespace std;
int main()
{
    long long shu;
    int imp;
    long long cx[10]={0};
    int i;
    int sc;
    int c,cc;
    cin>>shu;
    for(i=0;i<10;i++)
    {
        imp=1;
        while(imp<=shu)
        {
            cc=shu/(imp*10);
            cx[i]+=cc*imp;
            if(cc!=0 && i==0)cx[i]-=imp;
            sc=(cc*10+i)*imp;
            if(sc<=shu && sc!=0)
            {
                c=shu-sc+1;
                if(c>imp)c=imp;
                cx[i]+=c;
            }
            imp*=10;
        }
    }
    for(int i=0;i<10;i++)
    {
        if(i!=0)cout<<endl;
        cout<<cx[i];
    }
    return 0;
}
