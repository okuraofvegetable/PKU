#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
bool prime[1000000];
void eratos()
{
	memset(prime,true,sizeof(prime));
	prime[0]=false;
	prime[1]=false;
	for(int i=2;i*i<=1000000;i++)if(prime[i])
	{
		for(int j=i*2;j<1000000;j+=i)
		{
			prime[j]=false;
		}
	}
	prime[2]=false;
	return;
}
int main()
{
	eratos();
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)break;
		for(int i=3;i<=n/2;i++)
		{
			if(prime[i]&&prime[n-i])
			{
				printf("%d = %d + %d\n",n,i,n-i);
				goto end;
			}
		}
		end:;
	}
	return 0;
}
