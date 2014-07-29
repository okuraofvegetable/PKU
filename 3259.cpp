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
struct edge{int from,to,cost;};
vector<edge> e;
int n,m,w;
int dist[505];
void add_directed_edge(int a,int b,int c)
{
	edge in;
	in.from=a;in.to=b;in.cost=c;
	e.pb(in);
	return;
}
void add_undirected_edge(int a,int b,int c)
{
	edge in;
	in.from=a;in.to=b;in.cost=c;
	e.pb(in);
	swap(in.from,in.to);
	e.pb(in);
	return;
}
bool find_negative_loop()
{
	memset(dist,0,sizeof(dist));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<e.size();j++)
		{
			if(dist[e[j].to]>dist[e[j].from]+e[j].cost)
			{
				dist[e[j].to]=dist[e[j].from]+e[j].cost;
				if(i==n-1)return true;
			}
		}
	}
	return false;
}
int main()
{
	int f;
	scanf("%d",&f);
	while(f--)
	{
		e.clear();
		scanf("%d %d %d",&n,&m,&w);
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			add_undirected_edge(a,b,c);
		}
		for(int i=0;i<w;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			add_directed_edge(a,b,-c);
		}
		if(find_negative_loop())printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
