#include <cstdio>
using namespace std;
int main()
{
	int d,n,k;
	while(scanf("%d %d",&n,&k)!=EOF)
	{
		int ans=n;
		while(n>=k)
		{
			d=n/k;
			ans+=d;
			n%=k;
			n+=d;
		}
		printf("%d\n",ans);
	}
	return 0;
}
