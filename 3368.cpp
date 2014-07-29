#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
int SIZE;
struct segtree
{
	int seg[1<<18];
	void init(int n)
	{
		SIZE=1;
		while(SIZE<n)SIZE<<=1;
		memset(seg,0,sizeof(seg));
		return;
	}
	void update(int k,int x)
	{
		k+=SIZE-1;
		seg[k]=x;
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
		return;
	}
	int query(int a,int b,int k=0,int l=0,int r=SIZE)
	{
		if(r<=a||b<=l)return -1;
		else if(a<=l&&r<=b)return seg[k];
		else return max(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
	}
};
map<int,int> num;
int a[100100];
int n,q;
segtree seg;
int main()
{
	while(1)
	{
		memset(a,0,sizeof(a));
		num.clear();
		scanf("%d",&n);
		if(n==0)break;
		seg.init(n);
		scanf("%d",&q);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		num[a[0]]=0;
		for(int i=1;i<n;i++)
		{
			if(a[i]!=a[i-1])
			{
				int k=upper_bound(a,a+n,a[i-1])-lower_bound(a,a+n,a[i-1]);
				seg.update(num[a[i-1]],k);
				num[a[i]]=num[a[i-1]]+1;
			}
		}
		int k=upper_bound(a,a+n,a[n-1])-lower_bound(a,a+n,a[n-1]);
		seg.update(num[a[n-1]],k);
		for(int i=0;i<q;i++)
		{
			int s,t;
			scanf("%d %d",&s,&t);
			s--;t--;
			if(a[s]==a[t])
			{
				printf("%d\n",t-s+1);
				continue;
			}
			seg.update(num[a[s]],upper_bound(a+s,a+t+1,a[s])-lower_bound(a+s,a+t+1,a[s]));
			seg.update(num[a[t]],upper_bound(a+s,a+t+1,a[t])-lower_bound(a+s,a+t+1,a[t]));
			printf("%d\n",seg.query(num[a[s]],num[a[t]]+1));
			seg.update(num[a[s]],upper_bound(a,a+n,a[s])-lower_bound(a,a+n,a[s]));
			seg.update(num[a[t]],upper_bound(a,a+n,a[t])-lower_bound(a,a+n,a[t]));
		}
	}
	return 0;
}
