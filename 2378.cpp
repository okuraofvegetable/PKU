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
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
int n;
vector<int> G[10010];
int child[10010];
int depth[10010];
int dfs(int v,int p,int d)
{
	depth[v]=d;
	int ret=1;
	for(int i=0;i<G[v].size();i++)if(G[v][i]!=p)ret+=dfs(G[v][i],v,d+1);
	return child[v]=ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		G[a].pb(b);
		G[b].pb(a);
	}
	int root=1;
	dfs(root,0,0);
	for(int i=1;i<=n;i++)
	{
		int max_ret=0;
		for(int j=0;j<G[i].size();j++)
		{
			int e=G[i][j];
			if(depth[i]>depth[e])max_ret=max(max_ret,child[root]-child[i]);
			else max_ret=max(max_ret,child[e]);
		}
		if(max_ret<=n/2)printf("%d\n",i);
	}
	return 0;
}
