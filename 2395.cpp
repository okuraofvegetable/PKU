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
struct UnionFind
{
	int par[2010];
	int rank[2010];
	void init()
	{
		memset(rank,0,sizeof(rank));
		for(int i=0;i<2010;i++)par[i]=i;
		return;
	}
	int find(int x)
	{
		if(par[x]==x)return x;
		else return find(par[x]);
	}
	void unite(int a,int b)
	{
		a=find(a);
		b=find(b);
		if(rank[a]<rank[b])par[a]=b;
		else
		{
			par[b]=a;
			if(rank[a]==rank[b])rank[a]++;
		}
	}
	bool same(int a,int b)
	{
		return find(a)==find(b);
	}
};
UnionFind uf;
struct edge{int from,to,cost;};
vector<edge> edges;
int ans=0;
int n,m;
bool comp(edge a,edge b)
{
	return a.cost<b.cost;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		edge e;
		scanf("%d %d %d",&e.from,&e.to,&e.cost);
		edges.pb(e);
	}
	sort(edges.begin(),edges.end(),comp);
	uf.init();
	for(int i=0;i<edges.size();i++)
	{
		edge e = edges[i];
		if(!uf.same(e.from,e.to))
		{
			ans=max(ans,e.cost);
			uf.unite(e.from,e.to);
		}
	}
	printf("%d\n",ans);
	return 0;
}
