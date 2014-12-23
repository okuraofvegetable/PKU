#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 2000000000
int a[100100];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int N,S;
		scanf("%d %d",&N,&S);
		for(int i=0;i<N;i++)scanf("%d",&a[i]);
		int s=0,t=0;
		int ans = INF,sum = 0;
		while(s<N&&s<=t)
		{
			while(t<N&&sum<S)sum+=a[t++];
			if(sum<S)break;
			ans = min(ans,t-s);
			sum-=a[s++];
		}
		printf("%d\n",(ans==INF?0:ans));
	}
	return 0;
}
