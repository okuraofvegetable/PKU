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
bool dp[40200];
int n;
int maxa=0;
struct brock{int h,a,c;}item[450];
bool comp(brock a,brock b)
{
	return a.a<b.a;
}
int main()
{
	dp[0]=true;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&item[i].h,&item[i].a,&item[i].c);
		maxa=max(maxa,item[i].a);
	}
	sort(item,item+n,comp);
	for(int i=0;i<n;i++)
	{
		for(int j=item[i].a;j>=item[i].h;j--)
		{
			for(int k=0;k<=min((j/(item[i].h)),(item[i].c));k++)
			{
				dp[j]|=dp[(j-(item[i].h)*k)];
			}
		}
	}
	int ans=0;
	for(int i=0;i<=maxa;i++)if(dp[i])ans=max(ans,i);
	printf("%d\n",ans);
	return 0;
}
