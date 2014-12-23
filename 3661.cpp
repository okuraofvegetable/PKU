#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[10100][505];
int N,M;
int D[10010];
int main()
{
	scanf("%d %d",&N,&M);
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<N;i++)scanf("%d",&D[i]);
	dp[0][0]=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=M;j++)
		{
			if(j==0)dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			if(dp[i][j]==-1)continue;
			if(j<M)dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+D[i]);
			if(i+j<=N&&j>0)dp[i+j][0]=max(dp[i+j][0],dp[i][j]);
			//printf("%d %d %d\n",i,j,dp[i][j]);
		}
	}
	printf("%d\n",dp[N][0]);
	return 0;
}
