#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
int win[105],lose[105];
vector<int> g[105],rev[105];
int N,M;
bool used[105];
void dfs(int v)
{
	used[v]=true;
	for(int i=0;i<g[v].size();i++)if(!used[g[v][i]])dfs(g[v][i]);
	return;
}
void rdfs(int v)
{
	used[v]=true;
	for(int i=0;i<rev[v].size();i++)if(!used[rev[v][i]])rdfs(rev[v][i]);
	return;
}
int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		g[b].pb(a);
		rev[a].pb(b);
	}
	for(int i=0;i<N;i++)
	{
		memset(used,false,sizeof(used));
		dfs(i);
		for(int j=0;j<N;j++)if(j!=i&&used[j])lose[i]++;
		memset(used,false,sizeof(used));
		rdfs(i);
		for(int j=0;j<N;j++)if(j!=i&&used[j])win[i]++;
	}
	int ans = 0;
	for(int i=0;i<N;i++)if(win[i]+lose[i]==N-1)ans++;
	printf("%d\n",ans);
	return 0;
}
