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
int n,m;
vector<P> G[10010];
bool used[50010];
int vx[30020];
bool exist=false;
void dfs(int v,int d)
{
	//if(d==m*2)return;
	for(int i=0;i<G[v].size();i++)
	{
		if(!used[G[v][i].sec])
		{
			used[G[v][i].sec]=true;
			//vx[d]=G[v][i].fi;
			printf("%d\n",G[v][i].fi);
			dfs(G[v][i].fi,d+1);
			printf("%d\n",v);
		}
	}
	return;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		G[a].pb(mp(b,i));
		G[b].pb(mp(a,i));
	}
	printf("1\n");
	dfs(1,0);
	//for(int i=0;i<m*2;i++)printf("%d\n",vx[i]);
	return 0;
}
