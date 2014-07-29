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
double frac(int a,int b)
{
	return (double)(a)/(double)(b);
}
int main()
{
	double cur;
	int a,b;
	scanf("%d %d",&a,&b);
	cur=frac(a,b);
	int p,q;
	double d=INF;
	for(int i=1;i<=32767;i++)
	{
		if(i==b)continue;
		int s=1.0*i*a/b;
		for(int j=-1;j<=1;j++)
		{
			int w=s+j;
			if(__gcd(w,i)!=1)continue;
			double dist=abs(frac(w,i)-cur);
			if(dist<d)
			{
				p=w;q=i;
				d=dist;
			}
		}
	}
	printf("%d %d\n",p,q);
	return 0;
}
