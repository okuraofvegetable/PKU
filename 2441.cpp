#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[2][1<<20];
int g[22][22];
int N,M;
int cur=0,next=1;
int main()
{
	scanf("%d %d",&N,&M);
	memset(g,0,sizeof(g));
	for(int i=0;i<N;i++)
	{
		int p;
		scanf("%d",&p);
		for(int j=0;j<p;j++)
		{
			int k;
			scanf("%d",&k);k--;
			g[i][k]=1;
		}
	}
	memset(dp,0,sizeof(dp));
	for(int i=0;i<M;i++)if(g[0][i])dp[0][1<<i]=1;
	for(int i=1;i<N;i++)
	{
		for(int j=0;j<(1<<M);j++)
		{
			if(dp[cur][j]==0)continue;
			for(int k=0;k<M;k++)
			{
				if(!g[i][k])continue;
				if(j&(1<<k))continue;
				dp[next][j|(1<<k)]+=dp[cur][j];
			}
		}
		memset(dp[cur],0,sizeof(dp[cur]));
		swap(cur,next);
	}
	int ans = 0;
	for(int i=0;i<(1<<M);i++)
	{
		if(__builtin_popcount(i)==N)ans += dp[cur][i];
	}
	printf("%d\n",ans);
	return 0;
}
