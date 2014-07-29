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
P v[10010];
int main()
{
	int n,l,ans=0;
	scanf("%d %d",&n,&l);
	for(int i=0;i<n;i++)scanf("%d %d",&v[i].fi,&v[i].sec);
	sort(v,v+n);
	for(int i=0;i<n;i++)
	{
		if(v[i].fi>=v[i].sec)
		{
			if(i==n-1)break;
			v[i+1].fi=max(v[i+1].fi,v[i].fi);
			continue;
		}
		int num=v[i].sec-v[i].fi;
		int p=num/l+!!(num%l);
		ans+=p;
		if(i==n-1)break;
		int next=v[i].fi+l*p;
		v[i+1].fi=max(v[i+1].fi,next);
	}
	printf("%d\n",ans);
	return 0;
}
