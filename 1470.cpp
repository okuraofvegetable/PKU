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
int n,root;
vector<int> G[1000];
bool used[1000];
int depth[1000];
int ans[1000];
int par[1000][12];
void dfs(int v,int d)
{
	depth[v]=d;
	for(int i=0;i<G[v].size();i++)
	{
		par[G[v][i]][0]=v;
		dfs(G[v][i],d+1);
	}
	return;
}
void culc()
{
	for(int i=0;i<=10;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(par[j][i]<0)par[j][i+1]=-1;
			par[j][i+1]=par[par[j][i]][i];
		}
	}
	return;
}
int lca(int u,int v)
{
	if(depth[u]>depth[v])swap(u,v);
	int d=depth[v]-depth[u];
	for(int i=11;i>=0;i--)if((d>>i)&1)v=par[v][i];
	if(u==v)return u;
	for(int i=11;i>=0;i--)
	{
		if(par[u][i]!=par[v][i])
		{
			u=par[u][i];
			v=par[v][i];
		}
	}
	if(u==v)return u;
	return par[u][0];
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(par,-1,sizeof(par));
		memset(ans,0,sizeof(ans));
		memset(depth,0,sizeof(depth));
		memset(used,0,sizeof(used));
		for(int i=0;i<1000;i++)G[i].clear();
		for(int i=0;i<n;i++)
		{
			int s,k;
			char ig='P';
			scanf("%d",&s);
			while(ig!=':')scanf("%c",&ig);
			while(ig!='(')scanf("%c",&ig);
			scanf("%d",&k);
			while(ig!=')')scanf("%c",&ig);
			for(int j=0;j<k;j++)
			{
				int c;
				scanf("%d",&c);
				G[s].pb(c);
				used[c]=true;
			}
		}
		for(int i=1;i<=n;i++)if(!used[i])
		{
			root=i;
			break;
		}
		//cout << "Input finished." << endl;
		dfs(root,0);
		culc();
		//cout << "DFS finished." << endl;
		int q;
		scanf("%d",&q);
		for(int i=0;i<q;i++)
		{
			char ig;
			while(ig!='(')scanf("%c",&ig);
			int u,v;
			scanf("%d",&u);
			scanf("%d",&v);
			while(ig!=')')scanf("%c",&ig);
			//cout << "u " << u << endl;
			//cout << "v " << v << endl;
			ans[lca(u,v)]++;
		}
		for(int i=1;i<=n;i++)if(ans[i]>0)printf("%d:%d\n",i,ans[i]);
	}
	return 0;
}
