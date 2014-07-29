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
int N,T;
struct edge{int to,cost;};
vector<edge> g[1005];
int d[1005];
void dijkstra()
{
	fill(d,d+N,INF);
	d[0]=0;
	priority_queue<P,vector<P>,greater<P> > q;
	q.push(mp(0,0));
	while(!q.empty())
	{
		P a=q.top();
		q.pop();
		int v=a.sec;
		if(d[v]<a.fi)continue;
		for(int i=0;i<g[v].size();i++)
		{
			edge e=g[v][i];
			if(d[e.to]>d[v]+e.cost)
			{
				d[e.to]=d[v]+e.cost;
				q.push(mp(d[e.to],e.to));
			}
		}
	}
	return;
}
int main()
{
	scanf("%d %d",&T,&N);
	for(int i=0;i<T;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		a--;b--;
		edge in;
		in.to=b;in.cost=c;
		g[a].pb(in);
		in.to=a;
		g[b].pb(in);
	}
	dijkstra();
	printf("%d\n",d[N-1]);
	return 0;
}
