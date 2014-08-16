#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int,int> P;
#define INF 2000000000
#define fi first
#define sec second
int N;
P cow[50010];
bool comp(P a,P b)
{
	return a.fi+a.sec < b.fi+b.sec;
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d %d",&cow[i].fi,&cow[i].sec);
	sort(cow,cow+N,comp);
	int ans=-INF,sum=0;
	for(int i=0;i<N;i++)
	{
		ans=max(ans,sum-cow[i].sec);
		sum+=cow[i].fi;
	}
	printf("%d\n",ans);
	return 0;
}
