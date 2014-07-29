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
int main()
{
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)break;
		int ans=0;
		int cnt=0;
		while(n>=(cnt+1)*cnt/2)
		{
			ans+=cnt*cnt;
			cnt++;
		}
		ans+=(n-cnt*(cnt-1)/2)*cnt;
		printf("%d %d\n",n,ans);
	}
	return 0;
}
