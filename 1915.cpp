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
int f[350][350];
int dx[8]={1,1,2,2,-1,-1,-2,-2};
int dy[8]={2,-2,1,-1,2,-2,1,-1};
int l,sx,sy,gx,gy;
int bfs()
{
	memset(f,-1,sizeof(f));
	queue<P> q;
	q.push(mp(sx,sy));
	f[sx][sy]=0;
	while(!q.empty())
	{
		P a=q.front();q.pop();
		for(int i=0;i<8;i++)
		{
			int nx=a.fi+dx[i],ny=a.sec+dy[i];
			if(nx<0||nx>=l||ny<0||ny>=l)continue;
			if(f[nx][ny]!=-1)continue;
			f[nx][ny]=f[a.fi][a.sec]+1;
			if(nx==gx&&ny==gy)return f[nx][ny];
			q.push(mp(nx,ny));
		}
	}
	return f[gx][gy];
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&l);
		scanf("%d %d",&sx,&sy);
		scanf("%d %d",&gx,&gy);
		printf("%d\n",bfs());
	}
	return 0;
}
