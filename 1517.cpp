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
double func(int x)
{
	double ret=1.0;
	for(int i=1;i<=x;i++)ret*=i;
	return ret;
}
int main()
{
	printf("n e\n");
	printf("- -----------\n");
	double ans=0;
	for(int i=0;i<10;i++)
	{
		ans+=1.0/func(i);
		printf("%d %.9f\n",i,ans);
	}
	return 0;
}
