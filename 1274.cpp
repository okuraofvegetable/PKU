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
#define MAX_V 500
struct edge{int to,cap,rev;};
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];
void add_edge(int from,int to,int cap)
{
	G[from].pb((edge){to,cap,G[to].size()});
	G[to].pb((edge){from,0,G[from].size()-1});	
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
int main()
{
	int N,M,S,T;
	while(scanf("%d %d",&N,&M)!=EOF)
	{
		for(int i=0;i<MAX_V;i++)G[i].clear();
		S=0;T=N+M+1;
		//0:sorce,1~N:cows,N+1~N+M:stalls,N+M+1:target
		for(int i=1;i<=N;i++)add_edge(S,i,1);
		for(int i=1;i<=N;i++)
		{
			int k;
			scanf("%d",&k);
			for(int j=0;j<k;j++)
			{
				int a;
				scanf("%d",&a);
				add_edge(i,N+a,1);
			}
		}
		for(int i=1;i<=M;i++)add_edge(N+i,T,1);
		printf("%d\n",max_flow(S,T));
	}
	return 0;
}