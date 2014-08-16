#include <cstdio>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> T;
int a[100100];
int n;
vector<T> vec;
int main()
{
	int n,k;
	while(scanf("%d %d",&n,&k)!=EOF)
	{
		int s=0,t=0,sum=0;
		if(n==0&&k==0)break;
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		while(s<n)
		{
			while(t<n&&sum+a[t]<=0)sum+=a[t++];
			if(sum<=0)break;
			vec.push_back(T(sum,P(s,t-1)));
			sum-=a[s++];
		}
		sort(vec.begin(),vec.end());
		for(int i=0;i<k;i++)
		{
			int q;
			scanf("%d",&q);

