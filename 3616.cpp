#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> T;
#define fi first
#define sec second
#define INF 2000000000
int N,M,R;
T range[1010];
int dp[1010][1010];
int main()
{
	scanf("%d %d %d",&N,&M,&R);
	for(int i=0;i<M;i++)
	{
		scanf("%d %d %d",&range[i].fi.fi,&range[i].fi.sec,&range[i].sec);
	}
	sort(range,range+M);
	dp[0][0]=0;
	for(int i=1;i<M;i++)dp[0][i]=-INF;
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(dp[i][j]==-INF)continue;
			if(j==0)
			{
				dp[i+1][i+1]=range[i].sec;
				continue;
			}
			if(range[i].fi.fi-range[j-1].fi.sec>=R)
			{
				dp[i+1][i+1]=max(dp[i+1][i+1],dp[i][j]+range[i].sec);
			}
			dp[i+1][j]=max(dp[i][j],dp[i+1][j]);
		}
	}
	int ans=0;
	/*for(int i=0;i<=M;i++)
	{
		for(int j=0;j<=N;j++)
		{
			if(dp[i][j]==-INF)printf("- ");
			else printf("%d ",dp[i][j]);
		}
		puts("");
	}*/
	for(int i=0;i<=M;i++)ans=max(ans,dp[M][i]);
	printf("%d\n",ans);
	return 0;
}
