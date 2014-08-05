#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define INF 200000000000ll
ll N,K;
ll a[100100];
bool C(ll x)
{
	ll res=0;
	for(int i=0;i<N;i++)res+=(max(a[i]-x,0ll)+K-1)/K;
	return res <= x;
}
int main()
{
	scanf("%lld",&N);
	for(int i=0;i<N;i++)scanf("%lld",&a[i]);
	scanf("%lld",&K);
	if(K==1)
	{
		printf("%lld\n",*max_element(a,a+N));
		return 0;
	}
	K--;
	ll l=0ll,r=INF;
	while(r-l>1ll)
	{
		ll mid=(l+r)/2;
		if(C(mid))r=mid;
		else l=mid;
	}
	printf("%lld\n",r);
	return 0;
}
