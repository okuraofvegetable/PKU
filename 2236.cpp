#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
#define sq(X) ((X)*(X))
#define pb push_back
int N,d;
int x[1010],y[1010];
vector<int> g[1010];
bool live[1010];
int par[1010];
int rank[1010];
void init()
{
	for(int i=0;i<N;i++)
	{
		rank[i]=0;
		par[i]=i;
	}
	return;
}
int find(int x)
{
	if(par[x]==x)return x;
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
bool connected(int i,int j)
{
	if(sq(x[i]-x[j])+sq(y[i]-y[j])<=d*d)return true;
	else return false;
}
int main()
{
	memset(live,false,sizeof(live));
	scanf("%d %d",&N,&d);
	init();
	for(int i=0;i<N;i++)scanf("%d %d",&x[i],&y[i]);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(connected(i,j))
			{
				g[i].pb(j);
				g[j].pb(i);
			}
		}
	}
	char type;
	while(cin >> type)
	{
		if(type=='O')
		{
			int p;
			scanf("%d",&p);
			p--;
			live[p]=true;
			for(int i=0;i<g[p].size();i++)
			{
				if(live[g[p][i]])
				{
					unite(p,g[p][i]);
				}
			}
		}
		else
		{
			int a,b;
			scanf("%d %d",&a,&b);
			a--;b--;
			if(same(a,b))printf("SUCCESS\n");
			else printf("FAIL\n");
		}
	}
	return 0;
}
