#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define INF 100000000000000000ll
ll dp[110][210];
int cost[110];
int dist[110];
int main()
{
	int n,cnt=1;
	scanf("%d",&n);
	while(scanf("%d %d",&dist[cnt],&cost[cnt])!=EOF)cnt++;
	/*dist[cnt]=n;
	cnt++;*/
	for(int i=0;i<110;i++)
	{
		for(int j=0;j<210;j++)
		{
			dp[i][j]=INF;
		}
	}
	dp[0][100]=0;
	for(int i=1;i<cnt;i++)
	{
		int d=dist[i]-dist[i-1];
		if(d>200)break;
		for(int j=0;j<=200;j++)
		{
			if(j>=1)dp[i][j]=min(dp[i][j],dp[i][j-1]+cost[i]);
			if(j+d<=200)dp[i][j]=min(dp[i][j],dp[i-1][j+d]);
		}
	}
	ll ans=INF;
	for(int i=0;i<cnt;i++)
	{
		int d=abs(n-dist[i]);
		for(int j=100+d;j<=200;j++)ans=min(ans,dp[i][j]);
	}
	/*for(int i=0;i<9;i++)
	{
		for(int j=0;j<=200;j++)
		{
			if(dp[i][j]==INF)printf("- ");
			else printf("%d ",dp[i][j]);
		}
		puts("");
	}*/
	if(ans==INF)printf("Impossible\n");
	else printf("%lld\n",ans);
	return 0;
}
