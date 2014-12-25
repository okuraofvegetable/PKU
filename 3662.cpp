#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int,int> P;
#define INF 2000000000
#define MAX_L 1000000
#define pb push_back
int N,K,E;
int A[10010],B[10010],L[10010],d[1010];
struct edge
{
	int to,cost;
	edge(int to,int cost):to(to),cost(cost){}
};
vector<edge> g[1010];
void add_edge(int from,int to,int cost)
{
	g[from].pb(edge(to,cost));
	g[to].pb(edge(from,cost));
}
void dijkstra()
{
	fill(d,d+N,INF);
	d[0]=0;
	priority_queue<P,vector<P>,greater<P> > q;
	q.push(P(0,0));
	while(!q.empty())
	{
		P a = q.top();
		q.pop();
		int v = a.second;
		for(int i=0;i<g[v].size();i++)
		{
			edge e = g[v][i];
			if(d[e.to]>d[v]+e.cost)
			{
				d[e.to]=d[v]+e.cost;
				q.push(P(d[e.to],e.to));
			}
		}
	}
}
bool check(int x)
{
	for(int i=0;i<N;i++)g[i].clear();
	for(int i=0;i<E;i++)
	{
		if(L[i]<=x)add_edge(A[i],B[i],0);
		else add_edge(A[i],B[i],1);
	}
	dijkstra();
	if(d[N-1]<=K)return true;
	else return false;
}
int main()
{
	scanf("%d %d %d",&N,&E,&K);
	for(int i=0;i<E;i++)
	{
		scanf("%d %d %d",&A[i],&B[i],&L[i]);
		A[i]--;B[i]--;
	}
	int l = -1,r = MAX_L+1;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	int ans = (r==MAX_L+1)?-1:r;
	printf("%d\n",ans);
}
