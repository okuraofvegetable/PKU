#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
#define INF 2000000000
#define LLINF 100000000000000000ll
#define pb push_back
#define fi first
#define sec second
ll absll(ll x){return (x<0)?-x:x;}
int main()
{
	while(1)
	{
		int n;
		ll a[40];
		vector<P> l,r;
		vector<ll> val;
		scanf("%d",&n);
		if(n==0)break;
		for(int i=0;i<n;i++)scanf("%lld",&a[i]);
		l.clear();
		r.clear();
		ll ans = LLINF;
		int ansv = INF;
		for(int i=1;i<(1<<(n/2));i++)
		{
			ll sum = 0ll;
			int cnt = 0;
			for(int j=0;j<n/2;j++)if((i>>j)&1)
			{
				sum+=a[j];
				cnt++;
			}
			l.pb(P(sum,cnt));
		}
		for(int i=1;i<(1<<(n-n/2));i++)
		{
			ll sum = 0ll;
			int cnt = 0;
			for(int j=0;j<(n-n/2);j++)if((i>>j)&1)
			{
				sum+=a[n/2+j];
				cnt++;
			}
			val.pb(sum);
			r.pb(P(sum,cnt));
		}
		sort(l.begin(),l.end());
		sort(r.begin(),r.end());
		sort(val.begin(),val.end());
		val.erase(unique(val.begin(),val.end()),val.end());
		for(int i=0;i<l.size();i++)
		{
			if(ans >= absll(l[i].fi))
			{
				if(ans == absll(l[i].fi))ansv = min(ansv,l[i].sec);
				else ansv = l[i].sec;
				ans = absll(l[i].fi);
			}
		}
		for(int i=0;i<r.size();i++)
		{
			//printf("%lld %d\n",r[i].fi,r[i].sec);
			if(ans >= absll(r[i].fi))
			{
				if(ans == absll(r[i].fi))ansv = min(ansv,r[i].sec);
				else ansv = r[i].sec;
				ans = absll(r[i].fi);
			}
		}
		for(int i=0;i<l.size();i++)
		{
			//printf("%lld %d\n",l[i].fi,l[i].sec);
			vector<P>::iterator it;
			vector<ll>::iterator ite;
			ite  = lower_bound(val.begin(),val.end(),-(l[i].fi));
			if(ite!=val.end())
			{
				//printf("%lld\n",*ite);
				it = lower_bound(r.begin(),r.end(),P((*ite),0)); 
				if(ans >= absll(l[i].fi+(it->fi)))
				{
					if(ans == absll(l[i].fi+(it->fi)))ansv = min(ansv,l[i].sec+(it->sec));
					else ansv = l[i].sec+(it->sec);
					ans = absll(l[i].fi+(it->fi));
				}
			}
			if(ite!=val.begin())
			{
				ite--;
				//printf("%lld\n",*ite);
				it = lower_bound(r.begin(),r.end(),P((*ite),0));
				if(ans >= absll(l[i].fi+(it->fi)))
				{
					if(ans == absll(l[i].fi+(it->fi)))ansv = min(ansv,l[i].sec+(it->sec));
					else ansv = l[i].sec+(it->sec);
					ans = absll(l[i].fi+(it->fi));
				}
			}
		}
		printf("%lld %d\n",ans,ansv);
	}
	return 0;
}
