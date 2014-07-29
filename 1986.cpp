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
struct edge{int to,cost;};
const int SIZE=1<<17;
int N,M,K;
int k=0;
vector<edge> G[40010];
int depth[80010];
int dist[40010];
int vs[80010];
int id[40010];
P seg[SIZE*2];
void add_edge(int a,int b,int c)
{
	edge e;
	e.to=b;e.cost=c;
	G[a].pb(e);
	e.to=a;
	G[b].pb(e);
}
void dfs(int v,int p,int d)
{
	id[v]=k;
	vs[k]=v;
	depth[k++]=d;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i].to!=p)
		{
			dist[G[v][i].to]=dist[v]+G[v][i].cost;
			dfs(G[v][i].to,v,d+1);
			vs[k]=v;
			depth[k++]=d;
		}
	}
}
void construct_rmq()
{
	for(int i=0;i<k;i++)seg[i+SIZE-1]=mp(depth[i],i);
	for(int i=SIZE-2;i>=0;i--)seg[i]=min(seg[i*2+1],seg[i*2+2]);
}
P query(int a,int b,int k=0,int l=0,int r=SIZE)
{
	if(r<=a||b<=l)return mp(INF,-1);
	else if(a<=l&&r<=b)return seg[k];
	else return min(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
}
int lca(int u,int v)
{
	if(id[u]>id[v])swap(u,v);
	return vs[query(id[u],id[v]+1).sec];
}
int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)
	{
		char ig;
		int a,b,c;
		scanf("%d %d %d %c",&a,&b,&c,&ig);
		add_edge(a,b,c);
	}
	dfs(1,-1,0);
	construct_rmq();
	scanf("%d",&K);
	for(int i=0;i<K;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		int w=lca(u,v);
		printf("%d\n",dist[u]+dist[v]-dist[w]*2);
	}
	return 0;
}
