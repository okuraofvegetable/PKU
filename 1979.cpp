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
int w,h,sx,sy;
char f[22][22];
bool used[22][22];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int bfs()
{
	int ret=1;
	memset(used,false,sizeof(used));
	used[sx][sy]=true;
	queue<P> q;
	q.push(mp(sx,sy));
	while(!q.empty())
	{
		P a=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=a.fi+dx[i],ny=a.sec+dy[i];
			if(nx<0||nx>=h||ny<0||ny>=w)continue;
			if(used[nx][ny])continue;
			if(f[nx][ny]=='#'||f[nx][ny]=='@')continue;
			used[nx][ny]=true;
			//cout << nx << ' ' << ny << endl;
			ret++;
			q.push(mp(nx,ny));
		}
	}
	return ret;
}
int main()
{
	while(1)
	{
		scanf("%d %d",&w,&h);
		if(w==0&&h==0)break;
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				cin >> f[i][j];
				if(f[i][j]=='@')sx=i,sy=j;
			}
		}
		printf("%d\n",bfs());
	}
	return 0;
}
