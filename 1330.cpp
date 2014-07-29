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
int par[10100];
int main()
{
	int t;
	scanf("%d",&t);
	for(int c=0;c<t;c++)
	{
		int N;
		scanf("%d",&N);
		memset(par,-1,sizeof(par));
		for(int i=0;i<N-1;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			par[b]=a;
		}
		int u,v;
		scanf("%d %d",&u,&v);
		if(u==v)
		{
			printf("%d\n",u);
			continue;
		}
		vector<int> vx,vy;
		vx.pb(u);vy.pb(v);
		while(par[u]!=-1){vx.pb(par[u]);u=par[u];}
		while(par[v]!=-1){vy.pb(par[v]);v=par[v];}
		reverse(vx.begin(),vx.end());
		reverse(vy.begin(),vy.end());
		int cnt=0;
		while(cnt<vx.size()&&cnt<vy.size()&&vx[cnt]==vy[cnt])cnt++;
		if(vx[cnt]==vy[cnt])printf("%d\n",vx[cnt]);
		else printf("%d\n",vx[cnt-1]);
	}
	return 0;
}
