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
int h[20010];
int main()
{
	int N,B;
	scanf("%d %d",&N,&B);
	for(int i=0;i<N;i++)scanf("%d",&h[i]);
	sort(h,h+N);
	int ans,s=0,t=0,sum=0;
	while(sum<B)sum+=h[t++];
	ans=t-s;
	while(1)
	{
		sum-=h[s++];
		while(sum<B&&t<N)sum+=h[t++];
		if(sum<B)break;
		ans=min(ans,t-s);
	}
	printf("%d\n",ans);
	return 0;
}
