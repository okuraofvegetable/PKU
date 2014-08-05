#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> P;
#define fi first
#define sec second
int N,C,F,ans=-1,sum=0;
priority_queue<int> forth,back;
P cow[100100];
int forth_sum[100100];
int back_sum[100100];
int main()
{
	scanf("%d %d %d",&N,&C,&F);
	for(int i=0;i<C;i++)scanf("%d %d",&cow[i].fi,&cow[i].sec);
	sort(cow,cow+C);
	for(int i=0;i<N/2;i++)
	{
		sum+=cow[i].sec;
		forth.push(cow[i].sec);
	}
	for(int i=N/2;i<C-N/2;i++)
	{
		forth_sum[i]=sum;
		int fm=forth.top();
		if(fm>cow[i].sec)
		{
			sum-=fm;
			sum+=cow[i].sec;
			forth.pop();
			forth.push(cow[i].sec);
		}
	}
	sum=0;
	for(int i=C-1;i>=C-N/2;i--)
	{
		sum+=cow[i].sec;
		back.push(cow[i].sec);
	}
	for(int i=C-N/2-1;i>=N/2;i--)
	{
		back_sum[i]=sum;
		int bm=back.top();
		if(bm>cow[i].sec)
		{
			sum-=bm;
			sum+=cow[i].sec;
			back.pop();
			back.push(cow[i].sec);
		}
	}
	for(int i=N/2;i<C-N/2;i++)
	{
		//printf("%d %d\n",forth_sum[i],back_sum[i]);
		if(forth_sum[i]+cow[i].sec+back_sum[i]<=F)ans=cow[i].fi;
	}
	printf("%d\n",ans);
	return 0;
}
