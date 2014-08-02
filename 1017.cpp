#include <cstdio>
using namespace std;
int a[6];
int b[4]={0,5,3,1};
int sum=0;
int main()
{
	while(1)
	{
		int ans=0;
		int res1=0,res2=0;
		sum=0;
		for(int i=0;i<6;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum==0)break;
		ans=a[5]+a[4]+a[3]+a[2]/4;
		a[2]%=4;
		if(a[2]>0)ans++;
		res1+=11*a[4];
		res2+=5*a[3];
		res1+=20*a[3];
		if(a[2]>0)
		{
			res1+=36-a[2]*9;
			res2+=b[a[2]];
		}
		if(a[1]<=res2)
		{
			res2-=a[1];
			res1-=a[1]*4;
		}
		else
		{
			while(a[1]>res2)
			{
				res2+=9;
				res1+=36;
				ans++;
			}
			res2-=a[1];
			res1-=a[1]*4;
		}
		if(a[0]<=res1)res1-=a[0];
		else
		{
			while(a[0]>res1)
			{
				res1+=36;
				ans++;
			}
			res1-=a[0];
		}
		printf("%d\n",ans);
	}
	return 0;
}
