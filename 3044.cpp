#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int,int> P;
#define fi first
#define sec second
#define INF 2000000000
const int SIZE=1<<16;
P seg[SIZE*2];
int N,W,ans=0;
void build()
{
	for(int i=SIZE-1;i<SIZE*2-1;i++)seg[i].sec=i-SIZE+1;
	for(int i=SIZE-2;i>=0;i--)seg[i]=min(seg[i*2+1],seg[i*2+2]);
	return;
}
P query(int a,int b,int k,int l,int r)
{
	if(r<=a||b<=l)return P(INF,-1);
	else if(a<=l&&r<=b)return seg[k];
	else return min(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
}
void solve(int l,int r,int sum)
{
	if(r<=l)return;
	P a=query(l,r,0,0,SIZE);
	if(a.fi-sum>0)ans++;
	solve(l,a.sec,a.fi);
	solve(a.sec+1,r,a.fi);
	return;
}
int main()
{
	scanf("%d %d",&N,&W);
	for(int i=SIZE-1;i<SIZE*2-1;i++)seg[i].fi=INF;
	for(int i=0;i<N;i++)
	{
		int x;
		scanf("%d %d",&x,&seg[i+SIZE-1].fi);
	}
	build();
	solve(0,N,0);
	printf("%d\n",ans);
	return 0;
}
