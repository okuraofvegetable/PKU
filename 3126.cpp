#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define pb push_back
const int MAX=9999;
bool prime[10010];
vector<int> v;
vector<int> g[1100];
int d[1100];
int SZ;
bool comp(int a,int b)
{
	int diff=0;
	while(a>0)
	{
		if(a%10!=b%10)diff++;
		a/=10;
		b/=10;
	}
	return diff==1;
}
void bfs(int s,int t)
{
	memset(d,-1,sizeof(d));
	d[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int a=q.front();
		if(a==t)break;
		q.pop();
		for(int i=0;i<g[a].size();i++)
		{
			if(d[g[a][i]]==-1)
			{
				d[g[a][i]]=d[a]+1;
				q.push(g[a][i]);
			}
		}
	}
	printf("%d\n",d[t]);
	return;
}
void eratos()
{
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for(int i=2;i*i<MAX;i++)if(prime[i])
	{
		for(int j=i*2;j<=MAX;j+=i)
		{
			prime[j]=false;
		}
	}
	for(int i=1000;i<=MAX;i++)if(prime[i])v.pb(i);
	SZ=v.size();
	return;
}
int main()
{
	eratos();
	for(int i=0;i<SZ;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(comp(v[i],v[j]))
			{
				g[i].pb(j);
				g[j].pb(i);
			}
		}
	}
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		a=lower_bound(v.begin(),v.end(),a)-v.begin();
		b=lower_bound(v.begin(),v.end(),b)-v.begin();
		bfs(a,b);
	}
	return 0;
}
