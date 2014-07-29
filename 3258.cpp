#include <cstdio>
#include <algorithm>
using namespace std;
int N,M,L;
int a[500100];
bool C(int x)
{
	int d=0,cnt=0,rem=0;
	while(cnt<N)
	{
		while(cnt<N&&a[cnt++]-d<x)rem++;
		d=a[cnt-1];
	}
	if(a[N]-a[N-1]<x)rem++;
	if(rem<=M)return true;
	else return false;
}
int main()
{
	scanf("%d %d %d",&L,&N,&M);
	for(int i=0;i<N;i++)scanf("%d",&a[i]);
	sort(a,a+N);
	a[N]=L;
	int l=0,r=L;1;
	while(r-l>1)
	{
		int mid=(l+r)>>1;
		if(C(mid))l=mid;
		else r=mid;
	}
	printf("%d\n",l);
	return 0;
}
