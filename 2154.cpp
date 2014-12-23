#include <cstdio>
using namespace std;
typedef long long ll;
int MOD;
int mod_pow(ll a,int x)
{
	ll res=1;
	while(x>0)
	{
		if(x&1)res = (res*a)%MOD;
		a = (a*a)%MOD;
		x >>= 1;
	}
	return (int)res;
}
int euler(int x)
{
	int res = x;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			while(x%i==0)x/=i;
			res /= i;
			res *= i-1;
		}
	}
	if(x!=1)
	{
		res /= x;
		res *= x-1;
	}
	return res;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int s=0;s<t;s++)
	{
		int N,P;
		scanf("%d %d",&N,&P);
		MOD = P;
		int ans = 0;
		int cnt = 0;
		for(int i=1;i*i<=N;i++)
		{
			if(N%i==0)
			{
				ans +=((euler(N/i)%MOD)*(mod_pow(N,i-1)))%MOD;
				ans %= MOD;
				if(i!=N/i)ans +=((euler(i)%MOD)*(mod_pow(N,N/i-1)))%MOD;
				ans %= MOD;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
