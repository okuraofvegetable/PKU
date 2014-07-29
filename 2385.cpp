#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 2000000000
int dp[1050][40];
int apple[1050];
int T,W;
int main()
{
	scanf("%d %d",&T,&W);
	for(int i=0;i<T;i++)scanf("%d",&apple[i]);
	for(int i=0;i<T;i++)
	{
		for(int j=0;j<=W;j++)
		{
			dp[i][j]=-INF;
		}
	}
	dp[0][0]=0;
	for(int i=0;i<T;i++)
	{
		for(int j=0;j<=W;j++)
		{
			if(apple[i]==1&&j%2==0)
			{
				dp[i+1][j]=max(dp[i][j]+1,dp[i][j-1]+1);
			}
			else if(apple[i]==2&&j%2==1)
			{
				dp[i+1][j]=max(dp[i][j]+1,dp[i][j-1]+1);
			}
			else dp[i+1][j]=dp[i][j];
		}
	}
	int ans=0;
	for(int i=0;i<=W;i++)ans=max(ans,dp[T][i]);
	printf("%d\n",ans);
	return 0;
}
