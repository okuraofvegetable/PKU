#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 2000000000
int n,b;
int cow[25];
int ans=INF;
void dfs(int i,int sum)
{
	if(i==n)
	{
		if(sum>=b)ans=min(ans,sum-b);
		return;
	}
	dfs(i+1,sum);
	dfs(i+1,sum+cow[i]);
	return;
}
int main()
{
	scanf("%d %d",&n,&b);
	for(int i=0;i<n;i++)scanf("%d",&cow[i]);
	dfs(0,0);
	printf("%d\n",ans);
	return 0;
}
