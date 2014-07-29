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
int N,M,K;
struct edge{int to,dir,cost;};
struct query{int from,to,turn;};
vector<edge> G[40010];
P dist[40010];//fi:East sec:North
query Q[40010];
P mer[40010];
bool cmp_q(query a,query b)
{
	return a.turn < b.turn;
}
struct UnionFind
{
	int par[40010],rank[40010];
	void init()
	{
		memset(rank,0,sizeof(rank));
		for(int i=0;i<40010;i++)par[i]=i;
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
}uf;

void add_edge(int a,int b,int c,int d)//0:East 1:North
{
	edge p,q;
	p.to=b;p.dir=d;p.cost=c;
	q.to=a;q.dir=d;q.cost=-c;
	G[a].pb(p);
	G[b].pb(q);
}
void dfs(int v,int p)
{
	for(int i=0;i<G[v].size();i++)
	{
		edge e=G[v][i];
		if(e.to==p)continue;
		dist[e.to]=dist[v];
		if(e.dir)dist[e.to].sec+=e.cost;
		else dist[e.to].fi+=e.cost;
		dfs(e.to,v);
	}
	return;
}
int dis(int p,int q)
{
	return abs(dist[p].fi-dist[q].fi)+abs(dist[p].sec-dist[q].sec);
}
int main()
{
	uf.init();
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int f1,f2,L;
		char dir;
		scanf("%d %d %d %c",&f1,&f2,&L,&dir);
		mer[i].fi=f1;
		mer[i].sec=f2;
		if(dir=='E')add_edge(f1,f2,L,0);
		else if(dir=='W')add_edge(f1,f2,-L,0);
		else if(dir=='N')add_edge(f1,f2,L,1);
		else add_edge(f1,f2,-L,1);
	}
	dfs(1,-1);
	scanf("%d",&K);
	for(int i=0;i<K;i++)
	{
		scanf("%d %d %d",&Q[i].from,&Q[i].to,&Q[i].turn);
		Q[i].turn--;
	}
	sort(Q,Q+K,cmp_q);
	int cnt=0;
	for(int i=0;i<M;i++)
	{
		uf.unite(mer[i].fi,mer[i].sec);
		if(cnt==K)break;
		while(Q[cnt].turn==i&&cnt<K)
		{
			if(uf.same(Q[cnt].from,Q[cnt].to))
			{
				printf("%d\n",dis(Q[cnt].from,Q[cnt].to));
			}
			else printf("-1\n");
			cnt++;
		}
	}
	return 0;
}
