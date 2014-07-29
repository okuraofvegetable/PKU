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
int SIZE=1;
struct segtree
{
	int seg1[(1<<17)],seg2[(1<<17)];//max,min
	void update(int k,int x)
	{
		k+=SIZE-1;
		seg1[k]=x;seg2[k]=x;
		while(k>0)
		{
			k=(k-1)/2;
			seg1[k]=max(seg1[k*2+1],seg1[k*2+2]);
			seg2[k]=min(seg2[k*2+1],seg2[k*2+2]);
		}
	}
	void init(int k,int x)
	{
		k+=SIZE-1;
		seg1[k]=x;seg2[k]=x;
	}
	void build()
	{
		for(int k=SIZE-2;k>=0;k--)
		{
			seg1[k]=max(seg1[k*2+1],seg1[k*2+2]);
			seg2[k]=min(seg2[k*2+1],seg2[k*2+2]);
		}
	}
	int max_query(int a,int b,int k=0,int l=0,int r=SIZE)
	{
		if(r<=a||b<=l)return -1;
		else if(a<=l&&r<=b)return seg1[k];
		else return max(max_query(a,b,k*2+1,l,(l+r)/2),max_query(a,b,k*2+2,(l+r)/2,r));
	}
	int min_query(int a,int b,int k=0,int l=0,int r=SIZE)
	{
		if(r<=a||b<=l)return INF;
		else if(a<=l&&r<=b)return seg2[k];
		else return min(min_query(a,b,k*2+1,l,(l+r)/2),min_query(a,b,k*2+2,(l+r)/2,r));
	}
}seg;
int vx[(1<<17)][2];
int N,B,K;
int main()
{
	scanf("%d %d %d",&N,&B,&K);
	while(N*N>SIZE)SIZE*=2;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			int k;
			scanf("%d",&k);
			seg.init(i*N+j,k);
		}
	}
	seg.build();
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=N-B;j++)
		{
			vx[i*N+j][0]=seg.max_query(i*N+j,i*N+j+B);
			vx[i*N+j][1]=seg.min_query(i*N+j,i*N+j+B);
		}
	}
	for(int i=0;i<K;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		x--;y--;
		int mx=0,mi=INF;
		for(int j=x;j<x+B;j++)
		{
			mx=max(mx,vx[j*N+y][0]);
			mi=min(mi,vx[j*N+y][1]);
		}
		printf("%d\n",mx-mi);
	}
	return 0;
}
