#include <cstdio>
#include <queue>
#include <utility>
#include <functional>
using namespace std;
typedef pair<int,int> P;
#define INF 2000000000
#define fi first
#define sec second
#define pb push_back
int N,M,X;
struct edge
{
	int to,cost;
	edge(int to,int cost):to(to),cost(cost){}
};
vector<edge> G[2][1050];
int d[2][1010];
void add_edge(int from,int to,int cost)
{
	G[0][from].pb(edge(to,cost));
	G[1][to].pb(edge(from,cost));
	return;
}
void dijkstra(int s,int p)
{
	for(int i=0;i<N;i++)d[p][i]=INF;
	d[p][s]=0;
	priority_queue<P,vector<P>,greater<P> > q;
	q.push(P(0,s));
	while(!q.empty())
	{
		P a=q.top();
		q.pop();
		if(d[p][a.sec]<a.fi)continue;
		int v=a.sec;
		for(int i=0;i<G[p][v].size();i++)
		{
			edge e=G[p][v][i];
			if(d[p][e.to]>d[p][v]+e.cost)
			{
				d[p][e.to]=d[p][v]+e.cost;
				q.push(P(d[p][e.to],e.to));
			}
		}
	}
	return;
}
int main()
{
	scanf("%d %d %d",&N,&M,&X);
	X--;
	for(int i=0;i<M;i++)
	{
		int A,B,T;
		scanf("%d %d %d",&A,&B,&T);
		A--;B--;
		add_edge(A,B,T);
	}
	dijkstra(X,0);
	dijkstra(X,1);
	int ans=-1;
	for(int i=0;i<N;i++)ans=max(ans,d[0][i]+d[1][i]);
	printf("%d\n",ans);
	return 0;
}
