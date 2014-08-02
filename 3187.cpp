#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
int p[20];
int nCr(int n,int r)
{
	int res=1;
	for(int i=0;i<r;i++)res*=n-i;
	for(int i=1;i<=r;i++)res/=i;
	return res;
}
int main()
{
	int n,sum;
	scanf("%d %d",&n,&sum);
	for(int i=0;i<n;i++)p[i]=nCr(n-1,i);
	vector<int> v;
	for(int i=1;i<=n;i++)v.pb(i);
	do
	{
		int ret=0;
		for(int i=0;i<n;i++)ret+=p[i]*v[i];
		if(ret==sum)
		{
			for(int i=0;i<v.size();i++)
			{
				if(i!=v.size()-1)printf("%d ",v[i]);
				else printf("%d\n",v[i]);
			}
			break;
		}
	}
	while(next_permutation(v.begin(),v.end()));
	return 0;
}
