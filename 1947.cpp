#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
int n,p;
vector<int> g[200];
int dp[200][200];
int subtree_size[200];
void dfs(int v,int p)
{
	subtree_size[v]=1;
	int child=0;
	for(int i=0;i<g[v].size();i++)
	{
		if(g[v][i]!=p)
		{
			dfs(g[v][i],v);
			subtree_size[v]+=subtree_size[g[v][i]];
			child++;
		}
	}
	dp[v][1]=child;
	for(int i=0;i<g[v].size();i++)
	{
		int u=g[v][i];
		for(int j=subtree_size[v];j>1;j--)
		{
			for(int k=1;k<j;k++)
			{
				dp[v][j]=min(dp[v][j],dp[v][k]+dp[u][j-k]-1);
			}
		}
	}
	return;
}
int main()
{
	scanf("%d %d",&n,&p);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	for(int i=0;i<200;i++)
	{
		for(int j=0;j<200;j++)
		{
			dp[i][j]=INF;
		}
	}
	dfs(0,-1);
	int ans=INF;
	for(int i=0;i<n;i++)
	{
		if(i==0)ans=min(ans,dp[i][p]);
		else ans=min(ans,dp[i][p]+1);
	}
	printf("%d\n",ans);
	return 0;
}
