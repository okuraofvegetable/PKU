#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 200000000
int a[40010],dp[40010];
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		memset(a,0,sizeof(a));
		int p;
		scanf("%d",&p);
		fill(dp,dp+p,INF);
		for(int i=0;i<p;i++)scanf("%d",&a[i]);
		for(int i=0;i<p;i++)*lower_bound(dp,dp+p,a[i])=a[i];
		printf("%d\n",(int)(lower_bound(dp,dp+p,INF)-dp));
	}
	return 0;
}

