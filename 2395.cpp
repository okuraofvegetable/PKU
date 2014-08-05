#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define  INF 2000000000
int N,M,ans=-INF;
struct edge{int from,to,cost;};
bool comp(edge a,edge b)
{
	return a.cost<b.cost;
}
vector<edge> v;
struct UnionFind
{
	int par[2020],rank[2020];
	UnionFind()
	{
		for(int i=0;i<2020;i++)
		{
			par[i]=i;
			rank[i]=0;
		}
		return;
	}
	int find(int x)
	{
		if(x==par[x])return x;
		else return par[x]=find(par[x]);
	}
	void unite(int a,int b)
	{
		a=find(a);
		b=find(b);
		if(a==b)return;
		if(rank[a]<rank[b])par[a]=b;
		else
		{
			par[b]=a;
			if(rank[a]==rank[b])rank[a]++;
		}
		return;
	}
	bool same(int a,int b)
	{
		return find(a)==find(b);
	}
}uf;
int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)
	{
		edge e;
		scanf("%d %d %d",&e.from,&e.to,&e.cost);
		e.from--;e.to--;
		v.push_back(e);
	}
	sort(v.begin(),v.end(),comp);
	for(int i=0;i<v.size();i++)
	{
		if(!uf.same(v[i].from,v[i].to))
		{
			ans=max(ans,v[i].cost);
			uf.unite(v[i].from,v[i].to);
		}
	}
	printf("%d\n",ans);
	return 0;
}
