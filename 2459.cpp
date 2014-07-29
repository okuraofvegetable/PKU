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
int c,f1,f2,d;
int s[105],e[105];
int dist(int k,int x)
{
	if(s[k]>d||e[k]<x)return 0;
	if(e[k]>d)e[k]=d;
	return e[k]-max(s[k],x)+1;
}
int main()
{
	scanf("%d %d %d %d",&c,&f1,&f2,&d);
	for(int i=0;i<c;i++)
	{
		scanf("%d %d",&s[i],&e[i]);
	}
	int l=0,r=d;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		int res=0;
		for(int i=0;i<c;i++)res+=dist(i,mid);
		if(res<f1-f2)r=mid;
		else l=mid;
	}
	printf("%d\n",l);
	return 0;
}
