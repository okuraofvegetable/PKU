#include <cstdio>
using namespace std;
#define INF 2000000000
int n,m;
int a[100100];
bool C(int x)
{
	int id=0;
	for(int i=0;i<m;i++)
	{
		int sum=0;
		while(id<n&&(sum+a[id])<=x)
		{
			sum+=a[id];
			id++;
		}
		if(id==n)return true;
	}
	return false;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	int l=1,r=INF;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(C(mid))r=mid;
		else l=mid;
	}
	printf("%d\n",r);
	return 0;
}
