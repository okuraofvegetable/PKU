#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
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
#define EQ(a,b) (abs((a)-(b))<eps)
int dx[5]={0,0,0,1,-1};
int dy[5]={1,-1,0,0,0};
int N,M;
char f[20][20];
int base[20][20],now[20][20],ans[20][20];
int ans_num = 400;
void copy(){for(int i=0;i<M;i++)for(int j=0;j<N;j++)ans[i][j]=now[i][j];}
int get_color(int x,int y)
{
	int cnt=0;
	for(int i=0;i<5;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0||nx>=M||ny<0||ny>=N)continue;
		cnt += now[nx][ny];
	}
	return (base[x][y]+cnt)%2;
}
void solve(int x)
{
	int cnt = 0;
	memset(now,0,sizeof(now));
	for(int i=0;i<N;i++)
	{
		if((x>>i)&1)
		{
			now[0][N-1-i]=1;
			cnt++;
		}
	}
	for(int i=1;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(get_color(i-1,j)==1)
			{
				now[i][j]=1;
				cnt++;
			}
		}
	}
	bool flag = true;
	for(int i=0;i<M;i++)for(int j=0;j<N;j++)
	{
		if(get_color(i,j)==1)
		{
			flag = false;
			goto end;
		}
	}
	end:;
	if(flag&&ans_num>cnt)
	{
		ans_num = cnt;
		copy();
	}
	return;
}
int main()
{
	scanf("%d %d",&M,&N);
	for(int i=0;i<M;i++)for(int j=0;j<N;j++)scanf(" %c",&f[i][j]);
	for(int i=0;i<M;i++)for(int j=0;j<N;j++)base[i][j]=((f[i][j]=='0')?0:1);
	for(int i=0;i<(1<<N);i++)solve(i);
	if(ans_num==400)printf("IMPOSSIBLE\n");
	else
	{
		for(int i=0;i<M;i++)
		{
			for(int j=0;j<N;j++)printf("%d%c",ans[i][j],((j==N-1)?'\n':' '));
		}
	}
	return 0;
}
