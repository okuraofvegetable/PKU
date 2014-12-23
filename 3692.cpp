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
const int MAX_V=405;
int V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];
void add_edge(int u,int v)
{
	G[u].pb(v);
	G[v].pb(u);
}
bool dfs(int v)
{
	used[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		int u=G[v][i],w=match[u];
		if(w<0||!used[w]&&dfs(w))
		{
			match[v]=u;
			match[u]=v;
			return true;
		}
	}
	return false;
}
int bipartite_matching()
{
	int res=0;
	memset(match,-1,sizeof(match));
	for(int v=0;v<V;v++)
	{
		if(match[v]<0)
		{
			memset(used,0,sizeof(used));
			if(dfs(v))res++;
		}
	}
	return res;
}
bool exist[250][250];
int main()
{
	int t=0;
	while(++t)
	{
		for(int i=0;i<MAX_V;i++)G[i].clear();
		int G,B,M;
		scanf("%d %d %d",&G,&B,&M);
		if(G==0&&B==0&&M==0)break;
		V = G+B;
		memset(exist,false,sizeof(exist));
		for(int i=0;i<M;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			x--;y--;
			exist[x][y]=true;
		}
		for(int i=0;i<G;i++)
		{
			for(int j=0;j<B;j++)
			{
				if(!exist[i][j])add_edge(i,j+G);
			}
		}
		printf("Case %d: %d\n",t,V-bipartite_matching());
	}
	return 0;
}
