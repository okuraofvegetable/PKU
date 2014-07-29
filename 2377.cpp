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
	int par[1010];
	int rank[1010];
	void init()
	{
		for(int i=0;i<1010;i++)par[i]=i;
		memset(rank,0,sizeof(rank));
	}
	int find(int x)
	{
		if(par[x]==x)return x;
		else return find(par[x]);
	}
	int unite(int a,int b)
	{
		a=find(a);
		b=find(b);
		if(rank[a]>rank[b])par[b]=a;
		else
		{
			par[a]=b;
			if(rank[a]==rank[b])rank[b]++;
		}
	}
	bool same(int a,int b)
	{
		return find(a)==find(b);
	}
}uf;
int N,M;
struct edge{int from,to,cost;};
vector<edge> edges;
bool comp(edge a,edge b)
{
	return a.cost>b.cost;
}
int main()
{
	int ans=0;
	uf.init();
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		edge e;
		e.from=a;e.to=b;e.cost=c;
		edges.pb(e);
	}
	sort(edges.begin(),edges.end(),comp);
	for(int i=0;i<edges.size();i++)
	{
		if(!(uf.same(edges[i].from,edges[i].to)))
		{
			ans+=edges[i].cost;
			uf.unite(edges[i].from,edges[i].to);
		}
	}
	int root=uf.find(1);
	for(int i=1;i<=N;i++)if(uf.find(i)!=root)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",ans);
	return 0;
}
