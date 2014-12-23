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
const int MAX_V=250;
int N,M,S,T,F;
struct edge
{
	int to,cap,rev,val;
	edge(int to,int cap,int rev,int val):to(to),cap(cap),rev(rev),val(val){}
};
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];
int A[40010],B[40010],L[40010];
void add_edge(int from,int to,int cap,int val)
{
	edge new_edge1(to,cap,G[to].size(),val);
	G[from].pb(new_edge1);
	edge new_edge2(from,0,G[from].size()-1,val);
	G[to].pb(new_edge2);
}
void bfs(int s)
{
	memset(level,-1,sizeof(level));
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty())
	{
		int v=que.front();que.pop();
		for(int i=0;i<G[v].size();i++)
		{
			edge &e=G[v][i];
			if(e.cap>0&&level[e.to]<0)
			{
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}
int dfs(int v,int t,int f)
{
	if(v==t)return f;
	for(int &i=iter[v];i<G[v].size();i++)
	{
		edge &e=G[v][i];
		if(e.cap>0&&level[v]<level[e.to])
		{
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0)
			{
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t)
{
	int flow=0;
	for(;;)
	{
		bfs(s);
		if(level[t]<0)return flow;
		memset(iter,0,sizeof(iter));
		int f;
		while((f=dfs(s,t,INF))>0)flow+=f;
	}
}
void make_graph(int x)
{
	for(int i=0;i<250;i++)
	{
		for(int j=0;j<G[i].size();j++)
		{
			if(L[G[i][j].val]<=x)G[i][j].cap=1;
			else G[i][j].cap=0;
		}
	}
	return;
}
int main()
{
	scanf("%d %d %d",&N,&M,&F);
	for(int i=0;i<M;i++)
	{
		scanf("%d %d %d",&A[i],&B[i],&L[i]);
		add_edge(A[i],B[i],1,i);
	}
	S=1;T=N;
	int l = 0,r=1000001;
	while(r-l>1)
	{
		int mid = (l+r)/2;
		make_graph(mid);
		int f = max_flow(S,T);
		if(f>=F)r=mid;
		else l=mid;
	}
	printf("%d\n",r);
	return 0;
}
