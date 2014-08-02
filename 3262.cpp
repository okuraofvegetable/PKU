#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define fi first
#define sec second
int N;
ll sum=0,ans=0;
P T[100100];
bool comp(P a,P b)
{
	if(a.fi*b.sec-b.fi*a.sec<0)return true;
	else return false;
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&T[i].fi,&T[i].sec);
		sum+=T[i].sec;
	}
	sort(T,T+N,comp);
	for(int i=0;i<N;i++)
	{
		sum-=T[i].sec;
		//printf("%d %d\n",T[i].fi,T[i].sec);
		//printf("%d\n",sum*T[i].sec*2);
		ans+=sum*T[i].fi*2;
	}
	printf("%lld\n",ans);
	return 0;
}
