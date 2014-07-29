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
//コンパイラはG++ではなくC++にしないとTLEする。
int small[1000100],big[1000100];
int a[1000100];
int deq1[1000100],deq2[1000100];
int n,k,s1=0,t1=0,s2=0,t2=0;
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		while(s1<t1&&a[deq1[t1-1]]>=a[i])t1--;
		while(s2<t2&&a[deq2[t2-1]]<=a[i])t2--;
		deq1[t1++]=i;
		deq2[t2++]=i;
		if(i-k+1>=0)
		{
			small[i-k+1]=a[deq1[s1]];
			big[i-k+1]=a[deq2[s2]];
			if(deq1[s1]==i-k+1)s1++;
			if(deq2[s2]==i-k+1)s2++;
		}
	}
	for(int i=0;i<=n-k;i++)
	{
		if(i<n-k)printf("%d ",small[i]);
		else printf("%d\n",small[i]);
	}
	for(int i=0;i<=n-k;i++)
	{
		if(i<n-k)printf("%d ",big[i]);
		else printf("%d\n",big[i]);
	}
	return 0;
}
