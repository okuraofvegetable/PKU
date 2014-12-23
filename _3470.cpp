#include <cstdio>
#include <climits>
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
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define x first
#define y second
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<eps)
const int SIZE = 1<<19;
struct segtree
{
	P seg[SIZE*2],lazy[SIZE*2];
	segtree()
	{
		for(int i=0;i<SIZE*2;i++)seg[i]=P(-INF,-1),lazy[i]=P(-INF,-1);
	}
	inline void lazy_evaluate(int k)
	{
		seg[k] = max(seg[k],lazy[k]);
		if(k<SIZE-1)
		{
			lazy[k*2+1] = max(lazy[k*2+1],lazy[k]);
			lazy[k*2+2] = max(lazy[k*2+2],lazy[k]);
		}
		lazy[k]=P(-INF,-1);
	}
	inline void update_node(int k)
	{
		seg[k] = max(seg[k*2+1],seg[k*2+2]);
	}
	void update(int a,int b,int k,int l,int r,P x)
	{
		lazy_evaluate(k);
		if(r<=a||b<=l)return;
		else if(a<=l&&r<=b)
		{
			lazy[k]=x;
			lazy_evaluate(k);
			return;
		}
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,x);
			update(a,b,k*2+2,(l+r)/2,r,x);
			update_node(k);
		}
	}
	P query(int a,int b,int k,int l,int r)
	{
		lazy_evaluate(k);
		if(r<=a||b<=l)return P(-INF,-1);
		else if(a<=l&&r<=b)return seg[k];
		else 
		{
			P lch = query(a,b,k*2+1,l,(l+r)/2);
			P rch = query(a,b,k*2+2,(l+r)/2,r);
			update_node(k);
			return max(lch,rch);
		}
	}
	void update(int a,int b,P x)
	{
		if(a>b)swap(a,b);
		update(a,b,0,0,SIZE,x);
		return;
	}
	P query(int a,int b)
	{
		if(a>b)swap(a,b);
		return query(a,b,0,0,SIZE);
	}
}seg[4];
inline ll absll(ll x){return (x<0)?-x:x;}
int N,M;
int ans[50010];
P dist[4][50010];
P l[50010],r[50010],t[50010];
P L[50010],R[50010],T[50010];
void rotate()
{
	for(int i=0;i<N;i++)
	{
		swap(L[i].x,L[i].y);
		swap(R[i].x,R[i].y);
	}
	for(int i=0;i<M;i++)swap(T[i].x,T[i].y);
	for(int i=0;i<N;i++)
	{
		L[i].x *= -1ll;
		R[i].x *= -1ll;
	}
	for(int i=0;i<M;i++)T[i].x *= -1ll;
	return;
}
int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)scanf("%d %d %d %d",&L[i].x,&L[i].y,&R[i].x,&R[i].y);
	for(int i=0;i<M;i++)scanf("%d %d",&T[i].x,&T[i].y);
	for(int I=0;I<4;I++)
	{
		for(int i=0;i<N;i++)l[i]=L[i],r[i]=R[i];
		for(int i=0;i<M;i++)t[i]=T[i];
		vector<int> vx(N*2+M);
		vector<P> vy(N+M);
		for(int i=0;i<N;i++)if(l[i].x==r[i].x&&l[i].y>r[i].y)swap(l[i],r[i]);
		for(int i=0;i<N;i++)
		{
			vx[i*2]=l[i].x;vx[i*2+1]=r[i].x;
			vy[i]=P(r[i].y,i);
		}
		for(int i=0;i<M;i++)
		{
			vx[2*N+i]=t[i].x;
			vy[N+i]=P(t[i].y,-1-i);
		}
		sort(vx.begin(),vx.end());
		vx.erase(unique(vx.begin(),vx.end()),vx.end());
		sort(vy.begin(),vy.end());
		for(int i=0;i<N;i++)
		{
			l[i].x = lower_bound(vx.begin(),vx.end(),l[i].x)-vx.begin();
			r[i].x = lower_bound(vx.begin(),vx.end(),r[i].x)-vx.begin();
		}
		for(int i=0;i<M;i++)t[i].x = lower_bound(vx.begin(),vx.end(),t[i].x)-vx.begin();
		for(int i=0;i<N+M;i++)
		{
			if(vy[i].sec<=-1)
			{
				int id = -(vy[i].sec+1);
				P q = seg[I].query(t[id].x,t[id].x+1);
				if(q.sec==-1)
				{
					dist[I][id].fi=INF;
					dist[I][id].sec=-1;
				}
				else
				{
					dist[I][id].fi = absll(q.fi-vy[i].fi);
					dist[I][id].sec = q.sec;
				}
			}
			else
			{
				int id = vy[i].sec;
				seg[I].update(l[id].x,r[id].x+1,P(vy[i].fi,id));
			}
		}
		rotate();
	}
	/*for(int i=0;i<4;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout << dist[i][j].fi << ' ' << dist[i][j].sec << endl;
		}
	}*/
	memset(ans,0,sizeof(ans));
	for(int i=0;i<M;i++)
	{
		int near = -1;
		int d = INT_MAX;
		for(int j=0;j<4;j++)
		{
			if(dist[j][i].fi!=INF && d > dist[j][i].fi)
			{
				d = dist[j][i].fi;
				near = dist[j][i].sec;
			}
		}
		ans[near]++;
	}
	for(int i=0;i<N;i++)printf("%d\n",ans[i]);
	return 0;
}
