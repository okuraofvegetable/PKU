#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
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
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N;
int v[2010];
int imos[2010];
int dp[2010][2010];
int sum(int a,int b){return imos[b]-(a==0?0:imos[a-1]);}
int rec(int l,int r)
{
	if(l==r)return v[l];
	if(dp[l][r]!=-1)return dp[l][r];
	return dp[l][r]=max(v[l]+rec(l+1,r)+sum(l+1,r),v[r]+rec(l,r-1)+sum(l,r-1));
}
int main()
{
	scanf("%d",&N);
	rep(i,N)scanf("%d",&v[i]);
	rep(i,N)imos[i]=v[i];
	rep(i,N)imos[i+1]+=imos[i];
	memset(dp,-1,sizeof(dp));
	printf("%d\n",rec(0,N-1));
	return 0;
}
