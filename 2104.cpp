#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
const int B=1000;
int a[100100];
int A[100100];
vector<int> bucket[1005];
int n,q;
int query(int s,int t,int k)
{
	int l=-1,r=n-1;
	s--;t--;
	int L=s/B+1,R=t/B;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		int ret=0;
		for(int i=L;i<R;i++)ret+=upper_bound(bucket[i].begin(),bucket[i].end(),A[mid])-bucket[i].begin();
		if(L>=R)
		{
			for(int i=s;i<=t;i++)if(a[i]<=A[mid])ret++;
		}
		else
		{
			for(int i=s;i<L*B;i++)if(a[i]<=A[mid])ret++;
			for(int i=R*B;i<=t;i++)if(a[i]<=A[mid])ret++;
		}
		if(ret>=k)r=mid;
		else l=mid;
	}
	return A[r];
}
int main()
{
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		A[i]=a[i];
	}
	sort(A,A+n);
	for(int i=0;i<n;i++)bucket[i/B].pb(a[i]);
	for(int i=0;i<n/B;i++)sort(bucket[i].begin(),bucket[i].end());
	for(int i=0;i<q;i++)
	{
		int s,t,k;
		scanf("%d %d %d",&s,&t,&k);
		printf("%d\n",query(s,t,k));
	}
	return 0;
}
