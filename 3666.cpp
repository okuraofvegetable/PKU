#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define pb push_back
#define INF 2000000000
int N,sz;
int A[2020];
int dp[2020][2020];
vector<int> v;
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		v.pb(A[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	sz=v.size();
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<sz;j++)
		{
			if(j==0)dp[i+1][j]=dp[i][j]+abs(v[j]-A[i]);
			else dp[i+1][j]=min(dp[i][j],dp[i+1][j-1]-abs(v[j-1]-A[i]))+abs(v[j]-A[i]);
			//printf("%d ",dp[i+1][j]);
		}
		//puts("");
	}
	//puts("");
	int ans=INF;
	for(int i=0;i<sz;i++)ans=min(ans,dp[N][i]);
	memset(dp,0,sizeof(dp));
	reverse(v.begin(),v.end());
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<sz;j++)
		{
			if(j==0)dp[i+1][j]=dp[i][j]+abs(v[j]-A[i]);
			else dp[i+1][j]=min(dp[i][j],dp[i+1][j-1]-abs(v[j-1]-A[i]))+abs(v[j]-A[i]);
			//printf("%d ",dp[i+1][j]);
		}
		//puts("");
	}
	for(int i=0;i<sz;i++)ans=min(ans,dp[N][i]);
	printf("%d\n",ans);
	return 0;
}
