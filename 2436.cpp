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
int ans=0;
int v[1010];
int main()
{
	int n,d,K;
	scanf("%d %d %d",&n,&d,&K);
	for(int i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		for(int j=0;j<t;j++)
		{
			int e;
			scanf("%d",&e);
			e--;
			v[i]+=1<<e;
		}
	}
	for(int i=0;i<(1<<d);i++)
	{
		if(__builtin_popcount(i)>K)continue;
		int num=0;
		for(int j=0;j<n;j++)if((v[j]|i)==i)num++;
		ans=max(ans,num);
	}
	printf("%d\n",ans);
	return 0;
}
