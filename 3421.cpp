#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll; 
#define pb push_back
ll factorial(int k)
{
	ll ret=1ll;
	for(int i=2;i<=k;i++)ret*=i;
	return ret;
}
ll multinomial(vector<int> v,int sum)
{
	ll ret = factorial(sum);
	for(int i=0;i<v.size();i++) 
	{
		ret/=factorial(v[i]);
	}
	return ret;
}
int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		vector<int> v;
		int len=0,N_=N;
		for(int i=2;i*i<=N_;i++)
		{
			int cnt=0;
			while(N%i==0)
			{
				cnt++;
				N/=i;
			}
			len+=cnt;
			v.pb(cnt);
		}
		if(N!=1)
		{
			len++;
			v.pb(1);
		}
		printf("%d %lld\n",len,multinomial(v,len));
	}
	return 0;
}
