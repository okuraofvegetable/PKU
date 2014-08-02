#include <cstdio>
using namespace std;
#define MOD 1000000000ll
long long dp[1000100];
int main()
{
	int n;
	scanf("%d",&n);
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(i%2)dp[i]=dp[i-1];
		else dp[i]=(dp[i-1]+dp[i/2])%MOD;
	}
	printf("%lld\n",dp[n]);
	return 0;
}

