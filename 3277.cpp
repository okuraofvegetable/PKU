#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
#define pb push_back
ll A[40010],B[40010],H[40010];
vector<ll> vx;
vector<P> in,out;
multiset<ll> s;
int N;
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%lld %lld %lld",&A[i],&B[i],&H[i]);
		vx.pb(A[i]);
		vx.pb(B[i]);
	}
	vx.pb(0);
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<N;i++)
	{
		A[i]=lower_bound(vx.begin(),vx.end(),A[i])-vx.begin();
		B[i]=lower_bound(vx.begin(),vx.end(),B[i])-vx.begin();
		in.pb(P((int)A[i],H[i]));
		out.pb(P((int)B[i],H[i]));
	}
	sort(in.begin(),in.end());
	sort(out.begin(),out.end());
	ll ans = 0ll;
	s.insert(0ll);
	int in_id=0,out_id=0;
	for(int i=1;i<vx.size();i++)
	{
		ans += (vx[i]-vx[i-1])*(*s.rbegin());
		//printf("%lld %lld %lld\n",vx[i-1],vx[i],*s.rbegin());
		while(in_id<N&&in[in_id].first==i)
		{
			s.insert(in[in_id].second);
			//printf("insert %lld\n",in[in_id].second);
			in_id++;
		}
		while(out_id<N&&out[out_id].first==i)
		{
			multiset<ll>::iterator it;
			it = s.find(out[out_id].second);
			s.erase(it);
			//printf("erase %lld\n",out[out_id].second);
			out_id++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

