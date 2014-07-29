#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int bit[200100];
int num[200100];
int id[200100];
int ans[200100];
int n;
void add(int i,int x)
{
	while(i<=n)
	{
		bit[i]+=x;
		i+=i&-i;
	}
	return;
}
int sum(int i)
{
	int res=0;
	while(i>0)
	{
		res+=bit[i];
		i-=i&-i;
	}
	return res;
}
int find(int a)
{
	int l=-1,r=n-1;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		int p=mid-sum(mid+1);
		if(p>=a)r=mid;
		else l=mid;
	}
	return r;
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(bit,0,sizeof(bit));
		memset(num,0,sizeof(num));
		memset(id,0,sizeof(id));
		for(int i=0;i<n;i++)scanf("%d %d",&id[i],&num[i]);
		for(int i=n-1;i>=0;i--)
		{
			int k=find(id[i]);
			//cout << k << endl;
			ans[k]=num[i];
			add(k+1,1);
		}
		for(int i=0;i<n;i++)
		{
			if(i!=n-1)printf("%d ",ans[i]);
			else printf("%d\n",ans[i]);
		}
	}
	return 0;
}
