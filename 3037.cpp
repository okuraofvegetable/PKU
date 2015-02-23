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
typedef pair<long double,P> T;
typedef long double ld;
typedef vector<int> vi;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,x) for(int i=0;i<x;i++)
#define EQ(a,b) (abs((a)-(b))<eps)
int V,R,C;
int f[105][105];
ld d[105][105];
ld mul[130];
int geta = 60;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
ld INF;
ld Pow(int x){return mul[geta+x];}
ld dijkstra()
{
	rep(i,R)rep(j,C)d[i][j]=INF;
	priority_queue<T,vector<T>,greater<T> > q;
	d[0][0]=(ld)0.0;
	q.push(T((ld)0.0,P(0,0)));
	while(!q.empty())
	{
		T a=q.top();
		q.pop();
		int cx = a.sec.fi,cy = a.sec.sec;
		for(int i=0;i<4;i++)
		{
			int nx,ny;
			nx = cx + dx[i];
			ny = cy + dy[i];
			if(nx<0||nx>=R||ny<0||ny>=C)continue;
			if(d[nx][ny]>d[cx][cy]+Pow(f[cx][cy]))
			{
				d[nx][ny]=d[cx][cy]+Pow(f[cx][cy]);
				q.push(T(d[nx][ny],P(nx,ny)));
			}
		}
	}
	return d[R-1][C-1];
}
int main()
{
	mul[geta]=(ld)1.0;
	for(int i=1;i<=60;i++)
	{
		mul[geta+i]=mul[geta+i-1]*((ld)2.0);
		mul[geta-i]=mul[geta-i+1]/((ld)2.0);
	}
	INF = Pow(60);
	scanf("%d %d %d",&V,&R,&C);
	rep(i,R)rep(j,C)scanf("%d",&f[i][j]);
	rep(i,R)rep(j,C)if(i+j)f[i][j]-=f[0][0];
	f[0][0]=0;
	printf("%.2Lf\n",dijkstra()/(ld)V);
	return 0;
}
