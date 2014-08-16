#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
int n,k;
ll a[1010],b[1010];
bool C(double x)
{
	vector<double> v;
	double res=0ll;
	for(int i=0;i<n;i++)v.push_back(a[i]-b[i]*x);
	sort(v.begin(),v.end(),greater<double>());
	for(int i=0;i<n-k;i++)res+=v[i];
	return res>=0.0;
}
int main()
{
	while(scanf("%d %d",&n,&k)!=EOF)
	{
		if(n==0&&k==0)break;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++)scanf("%lld",&a[i]);
		for(int i=0;i<n;i++)scanf("%lld",&b[i]);
		double l=0,r=1000000000;
		for(int i=0;i<100;i++)
		{
			double mid=(l+r)/2ll;
			if(C(mid))l=mid;
			else r=mid;
		}
		printf("%d\n",(int)(l*100+0.5));
	}
	return 0;
}
