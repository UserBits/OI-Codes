#include <cstdio>
using namespace std;
int main()
{
	double a,b,c,left,right,num,temp,mid;
    scanf("%lf%lf%lf",&a,&b,&c);
    left=0.0;
    right=1000.0;
    while(left<right)
    {
        mid=(left+right)/2.0;
        num=mid/100.0+1.0;
        temp=0.0;
        for(int i=0;i<c;i++)
        {
            temp+=b/num;
            num=num*(mid/100.0+1.0);
        }
        if(temp>a)
        	left=mid+0.00001;
        else
        	right=mid-0.00001;
    }
    if(left<=0)
    	printf("0.0");
    else
   		printf("%.1lf\n",right);
	return 0;
}

