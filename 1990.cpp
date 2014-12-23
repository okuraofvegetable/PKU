#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
#define pb push_back
#define fi first
#define sec second
struct BIT
{
	ll bit[50000];
	BIT()
	{
		memset(bit,0,sizeof(bit));
	}
	void add(int i,ll x)
	{
		while(i<=30000)
		{
			bit[i]+=x;
			i+=i&-i;
		}
	}
	ll sum(int i)
	{
		ll res = 0ll;
		while(i>0)
		{
			res += bit[i];
			i-=i&-i;
		}
		return res;
	}
};
BIT bit,cnt;
int N;
vector<P> points;
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int v,x;
		scanf("%d %d",&v,&x);
		points.pb(P(v,x));
	}
	sort(points.begin(),points.end());
	ll sum = 0ll,ans = 0ll;
	for(int i=0;i<N;i++)
	{
		ll v = points[i].fi,x = points[i].sec;
		ll small = cnt.sum(x);
		ll small_sum = bit.sum(x);
		ans += v*(x*small-small_sum*2+sum-x*(i-small));
		cnt.add(x,1);
		bit.add(x,x);
		sum += x;
	}
	printf("%lld\n",ans);
	return 0;
}
