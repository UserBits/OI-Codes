#include<iostream>
#include<cstdio>
using namespace std;
int n,num=0,project[10];
int big[9000][10];
int i,a;
int step(int remain_n,int deep,int* now_project_p)
{
    if(remain_n<(10-deep) || remain_n>(3*(10-deep)))
        return 0;
    if(remain_n==0)
    {
        num++;
        for(int o=0;o<10;o++)
        {
            big[num-1][o+1]=*(now_project_p+o);
        }
        return 0;
    }
    for(int z=1;z<=3;z++)
    {
        *(now_project_p+deep)=z;
        step(remain_n-z,deep+1,now_project_p);
    }
    return 0;
}
int main()
{
    cin>>n;
    step(n,0,&project[0]);
    cout<<num<<endl;
    for(i=0;i<num;i++)
    {
        for(a=0;a<10;a++)
            cout<<big[i][a+1]<<" ";
        cout<<endl;
    }
    return 0;
}
