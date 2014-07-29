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
int n;
ll a[10100];
ll b[10100];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	sort(a,a+n);
	for(int i=0;i<n;i++)b[i]=a[i];
	for(int i=1;i<n;i++)b[i]+=b[i-1];
	ll ans=0ll;
	for(int i=0;i<n;i++)
	{
		ans+=(b[n-1]-b[i])-a[i]*(n-1-i);
		if(i>0)ans+=a[i]*i-b[i-1];
	}
	printf("%lld\n",ans);
	return 0;
}
