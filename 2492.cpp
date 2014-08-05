#include <cstdio>
using namespace std;
const int SIZE=4010;
struct UnionFind
{
	int par[SIZE],rank[SIZE];
	void init()
	{
		for(int i=0;i<SIZE;i++)
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
	for(int t=0;t<T;t++)
	{
		int N,Q;
		scanf("%d %d",&N,&Q);
		uf.init();
		for(int i=0;i<Q;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			uf.unite(a,b+N);
			uf.unite(a+N,b);
		}
		bool flag=false;
		for(int i=1;i<=N;i++)if(uf.same(i,i+N))
		{
			flag=true;
			break;
		}
		if(flag)printf("Scenario #%d:\nSuspicious bugs found!\n",t+1);
		else printf("Scenario #%d:\nNo suspicious bugs found!\n",t+1);
		printf("\n");
	}
	return 0;
}
