#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
vector<int> g[5050],rev[5050];
int dp[5050],dp2[5050],e[5050];
int N,M;
int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		e[b]++;
		g[a].pb(b);
		rev[b].pb(a);
	}
	for(int i=1;i<=N;i++)if(e[i]==0)
	{
		g[0].pb(i);
		rev[i].pb(0);
	}
	dp[0]=1;
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<rev[i].size();j++)dp[i]+=dp[rev[i][j]];
	}
	dp2[N]=1;
	for(int i=N-1;i>=0;i--)
	{
		for(int j=0;j<g[i].size();j++)dp2[i]+=dp2[g[i][j]];
	}
	int ans = 0;
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<g[i].size();j++)ans = max(ans,dp[i]*dp2[g[i][j]]);
	}
	printf("%d\n",ans);
	return 0;
}
