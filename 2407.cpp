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
void solve(int n)
{
	vector<int> ret;
	int ans=n,n_=n;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ret.pb(i);
			while(n%i==0)n/=i;
		}
	}
	if(n!=1)ret.pb(n);
	int sz=ret.size();
	for(int i=1;i<(1<<sz);i++)
	{
		int num=1;
		for(int j=0;j<sz;j++)if((i>>j)&1)num*=ret[j];
		if(__builtin_popcount(i)%2==0)ans+=n_/num;
		else ans-=n_/num;
	}
	printf("%d\n",ans);
	return;
}
int main()
{
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)break;
		solve(n);
	}
	return 0;
}
