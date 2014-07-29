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
set<P> s;
P point[205];
P sim(P a)
{
	if(a.fi==0)return P(0,1);
	if(a.sec==0)return P(1,0);
	if(a.fi<0)
	{
		a.fi*=-1;
		a.sec*=-1;
	}
	int x=abs(a.fi),y=abs(a.sec);
	int g=__gcd(x,y);
	return P(a.fi/g,a.sec/g);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d %d",&point[i].fi,&point[i].sec);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)continue;
			P k=P(point[i].fi-point[j].fi,point[i].sec-point[j].sec);
			s.insert(sim(k));

		}
	}
	cout << s.size() << endl;
	return 0;
}
