#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define INF 10000000000000000ll
int L,N,B;
struct block
{
	int x,w,c;
	ll f;
};
block co[100100];
ll dp[1050][1050];
bool comp(block a,block b)
{
	return a.x<b.x;
}
int main()
{
	scanf("%d %d %d",&L,&N,&B);
	for(int i=0;i<N;i++)scanf("%d %d %lld %d",&co[i].x,&co[i].w,&co[i].f,&co[i].c);
	sort(co,co+N,comp);
	for(int i=0;i<1050;i++)
	{
		for(int j=0;j<1050;j++)
		{
			dp[i][j]=INF;
		}
	}
	dp[0][0]=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=B-co[i].c;j++)
		{
			if(dp[co[i].x][j]!=INF)
			{
				if(dp[co[i].x+co[i].w][j+co[i].c]==INF)dp[co[i].x+co[i].w][j+co[i].c]=dp[co[i].x][j]+co[i].f;
				else dp[co[i].x+co[i].w][j+co[i].c]=max(dp[co[i].x+co[i].w][j+co[i].c],dp[co[i].x][j]+co[i].f);
			}
		}
	}
	ll ans=-1;
	/*for(int i=0;i<=5;i++)
	{
		for(int j=0;j<=10;j++)
		{
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}*/
	for(int i=0;i<=B;i++)if(dp[L][i]!=INF)ans=max(ans,dp[L][i]);
	if(ans==-1)printf("-1\n");
	else printf("%lld\n",ans);
	return 0;
}
