#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int n;
ll num;
int a[100100];
ll C(int x)
{
	ll res=0ll;
	for(int i=0;i<n;i++)
	{
		int k=upper_bound(a,a+n,a[i]+x)-a;
		res+=k-i-1;
	}
	return res;
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		sort(a,a+n);
		num = ((ll)n)*((ll)(n-1))/2ll;
		if(num%2==1)num++;
		num/=2ll;
		int l=-1,r=1000000000;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			if(C(mid)>=num)r=mid;
			else l=mid;
		}
		printf("%d\n",r);
	}
	return 0;
}
