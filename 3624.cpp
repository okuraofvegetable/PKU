#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 2000000000
int N,M;
int W[3500],D[3500];
int dp[2][13000];
//dp[i+1][j]:=i番目までのcharmで重さjのときのmax
int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)scanf("%d %d",&W[i],&D[i]);
	for(int i=0;i<=M;i++)dp[0][i]=-INF;
	dp[0][0]=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=M;j++)
		{
			if(j-W[i]>=0)dp[(i+1)%2][j]=max(dp[i%2][j-W[i]]+D[i],dp[i%2][j]);
			else dp[(i+1)%2][j]=dp[i%2][j];
		}
	}
	int ans = -INF;
	for(int i=0;i<=M;i++)ans = max(ans,dp[N%2][i]);
	printf("%d\n",ans);
	return 0;
}
