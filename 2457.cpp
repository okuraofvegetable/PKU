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
vector<int> G[50010];
int prev[50010];
bool used[50010];
int n,m;
void bfs()
{
	queue<int> q;
	q.push(1);
	used[1]=true;
	while(!q.empty())
	{
		int a=q.front();
		q.pop();
		for(int i=0;i<G[a].size();i++)
		{
			if(!used[G[a][i]])
			{
				prev[G[a][i]]=a;
				used[G[a][i]]=true;
				q.push(G[a][i]);
				if(G[a][i]==m)return;
			}
		}
	}
	return;
}
int main()
{
	memset(prev,-1,sizeof(prev));
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		G[a].pb(b);
	}
	bfs();
	//for(int i=1;i<=5;i++)cout << prev[i] << endl;
	if(!used[m])
	{
		printf("-1\n");
		return 0;
	}
	vector<int> ans;
	for(int i=m;prev[i]!=-1;i=prev[i])ans.pb(i);
	reverse(ans.begin(),ans.end());
	int sz=ans.size();
	printf("%d\n",sz+1);
	printf("1\n");
	for(int i=0;i<ans.size();i++)printf("%d\n",ans[i]);
	return 0;
}
