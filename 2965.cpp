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
string f[4];
int first=0,state;
int ans,num=INF;
int mask[16];
void solve(int p)
{
	int cnt=0;
	for(int i=0;i<16;i++)if((p>>i)&1)state^=mask[i],cnt++;
	if(cnt>=num)return;
	if(state==0)
	{
		num=cnt;
		ans=p;
	}
}
int main()
{
	for(int i=0;i<4;i++)cin >> f[i];
	for(int i=0;i<16;i++)
	{
		int w=i/4,r=i%4;
		for(int j=w*4;j<w*4+4;j++)mask[i]|=1<<j;
		for(int j=0;j<4;j++)mask[i]|=1<<(4*j+r);
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(f[i][j]=='+')first|=1<<(i*4+j);
		}
	}
	for(int i=0;i<(1<<16);i++)
	{
		state=first;
		solve(i);
	}
	printf("%d\n",num);
	for(int i=0;i<16;i++)if((ans>>i)&1)printf("%d %d\n",i/4+1,(i%4)+1);
	return 0;
}
