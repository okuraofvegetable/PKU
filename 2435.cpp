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
typedef pair<char,int> Pc;
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
char f[100][100];
P prev[100][100];
bool used[100][100];
int N,E,W,H;
int sx,sy,gx,gy;
int cx[4]={0,0,1,-1};
int cy[4]={1,-1,0,0};
int dx[4]={0,0,2,-2};
int dy[4]={2,-2,0,0};
vector<P> vec;
vector<Pc>ans;
void bfs()
{
	W=N*2-1;
	H=E*2-1;
	used[sx][sy]=true;
	queue<P> q;
	q.push(mp(sx,sy));
	while(!q.empty())
	{
		P a=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int mx=a.fi+cx[i],my=a.sec+cy[i];
			if(mx<0||mx>=W||my<0||my>=H)continue;
			if(f[mx][my]=='.')continue;
			int nx=a.fi+dx[i],ny=a.sec+dy[i];
			if(used[nx][ny])continue;
			prev[nx][ny]=a;
			used[nx][ny]=true;
			if(f[nx][ny]=='E')goto end;
			q.push(mp(nx,ny));
		}
	}
	end:;
	return;
}
int main()
{
	scanf("%d %d",&N,&E);
	for(int i=0;i<N*2-1;i++)
	{
		for(int j=0;j<E*2-1;j++)
		{
			cin >> f[i][j];
			if(f[i][j]=='S')sx=i,sy=j;
			if(f[i][j]=='E')gx=i,gy=j;
		}
	}
	bfs();
	for(P i=P(gx,gy);i!=P(sx,sy);i=prev[i.fi][i.sec])vec.pb(i);
	vec.pb(mp(sx,sy));
	reverse(vec.begin(),vec.end());
	for(int i=1;i<vec.size();i++)
	{
		int tx=vec[i].fi-vec[i-1].fi,ty=vec[i].sec-vec[i-1].sec;
		if(tx==2&&ty==0)
		{
			if(!ans.empty()&&(ans.back()).fi=='S')ans[ans.size()-1].sec++;
			else ans.pb(Pc('S',1));
		}
		else if(tx==-2&&ty==0)
		{
			if(!ans.empty()&&(ans.back()).fi=='N')ans[ans.size()-1].sec++;
			else ans.pb(Pc('N',1));
		}
		else if(tx==0&&ty==2)
		{
			if(!ans.empty()&&(ans.back()).fi=='E')ans[ans.size()-1].sec++;
			else ans.pb(Pc('E',1));
		}
		else
		{
			if(!ans.empty()&&(ans.back()).fi=='W')ans[ans.size()-1].sec++;
			else ans.pb(Pc('W',1));
		}
	}
	for(int i=0;i<ans.size();i++)printf("%c %d\n",ans[i].fi,ans[i].sec);
	return 0;
}
