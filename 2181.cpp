#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int dp[2];
int main()
{
	dp[0]=0;
	dp[1]=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int k;
		scanf("%d",&k);
		dp[0]=max(dp[0],dp[1]+k);
		dp[1]=max(dp[1],dp[0]-k);
	}
	printf("%d\n",max(dp[0],dp[1]));
	return 0;
}
