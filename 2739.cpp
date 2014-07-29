#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define pb push_back
vector<int> primes;
bool prime[10010];
void eratos()
{
	memset(prime,true,sizeof(prime));
	prime[0]=false;
	prime[1]=false;
	for(int i=2;i<=100;i++)
	{
		if(prime[i])
		{
			for(int j=i*2;j<=10000;j+=i)
			{
				prime[j]=false;
			}
		}
	}
	for(int i=2;i<=10000;i++)if(prime[i])primes.pb(i);
	return;
}
int cnt(int x)
{
	int s=0,t=0,sum=0;
	int ret=0;
	while(s<primes.size())
	{
		while(sum<x&&t<primes.size())
		{
			sum+=primes[t];
			t++;
		}
		if(sum==x)ret++;
		sum-=primes[s];
		s++;
	}
	return ret;
}
int main()
{
	eratos();
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)break;
		printf("%d\n",cnt(n));
	}
	return 0;
}
