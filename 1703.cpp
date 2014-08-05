#include <cstdio>
using namespace std;
struct UnionFind
{
	int par[200100],rank[200100];
	void init()
	{
		for(int i=0;i<200100;i++)
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
	int T;
	scanf("%d",&T);
	while(T--)
	{
		uf.init();
		int N,Q;
		scanf("%d %d",&N,&Q);
		for(int i=0;i<Q;i++)
		{
			char type;
			int a,b;
			scanf(" %c %d %d",&type,&a,&b);
			if(type=='A')
			{
				if(uf.same(a,b))printf("In the same gang.\n");
				else if(uf.same(a,b+N)||uf.same(a+N,b))printf("In different gangs.\n");
				else printf("Not sure yet.\n");
			}
			else
			{
				uf.unite(a,b+N);
				uf.unite(a+N,b);
			}
		}
	}
	return 0;
}
