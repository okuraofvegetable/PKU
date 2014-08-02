#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 2000000000
int N;
int f[400][400];
int dp[400][400];
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=i;j++)
		{
			scanf("%d",&f[i][j]);
			dp[i][j]=-INF;
		}
	}
	dp[0][0]=f[0][0];
	for(int i=0;i<N-1;i++)
	{
		for(int j=0;j<=i;j++)
		{
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]+f[i+1][j]);
			dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+f[i+1][j+1]);
		}
	}
	int ans=-INF;
	for(int i=0;i<N;i++)ans=max(ans,dp[N-1][i]);
	printf("%d\n",ans);
	return 0;
}
