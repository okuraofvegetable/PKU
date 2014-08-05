#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 2000000000
int geta=100100;
int dp[2][202000];
int N;
int S[105],F[105];
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d %d",&S[i],&F[i]);
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<202000;j++)
		{
			dp[i][j]=-INF;

		}
	}
	dp[0][geta]=0;
	for(int i=0;i<N;i++)
	{
		if(S[i]<0)
		{
			for(int j=200000;j>=0;j--)
			{
				dp[(i+1)%2][j]=max(dp[i%2][j],dp[i%2][j-S[i]]+F[i]+S[i]);
			}
		}
		else
		{
			for(int j=S[i];j<=200000;j++)
			{
				dp[(i+1)%2][j]=max(dp[i%2][j],dp[i%2][j-S[i]]+F[i]+S[i]);
			}
		}
	}
	int ans=0;
	for(int i=geta;i<=200000;i++)
	{
		if(dp[N%2][i]-(i-geta)<0)continue;
		ans=max(ans,dp[N%2][i]);
	}
	printf("%d\n",ans);
	return 0;
}
