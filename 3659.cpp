#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define INF 2000000000
int N;
vector<int> g[10010];
vector<int> child[10010];
int root=0;
int ans=INF;
void dfs(int v,int p)
{
	for(int i=0;i<g[v].size();i++)
	{
		if(g[v][i]==p)continue;
		child[v].pb(g[v][i]);
		dfs(g[v][i],v);
	}
	return;
}
int dp(int v,bool use)
{
	if(child[v].size()==0)
	{
		if(use)return 1;
		else return 0;
	}
	int ret=INF;
	for(int i=0;i<child[v].size();i++)ret=min(ret,dp(child[v][i],true));
	if(!use)
	{
		//cout <<  v << ':' << ret << endl;
		return ret;
	}
	for(int i=0;i<child[v].size();i++)ret=min(ret,dp(child[v][i],false));
	//cout << v << ':' << ret+1 << endl;
	return ret+1;
}		
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(root,-1);
	/*for(int i=0;i<N;i++)
	{
		cout << i << ':';
		for(int j=0;j<child[i].size();j++)
		{
			cout << child[i][j] << ' ';
		}
		cout << endl;
	}*/
	//cout << dp(root,true) << endl;
	//cout << dp(root,false) << endl;
	ans = min(ans,dp(root,true));
	ans = min(ans,dp(root,false));
	printf("%d\n",ans);
	return 0;
}
