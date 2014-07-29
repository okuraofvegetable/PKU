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
int dp[22][22][22];
int w(int a,int b,int c)
{
	if(a<=0||b<=0||c<=0)return 1;
	if(a>20||b>20||c>20)return w(20,20,20);
	if(dp[a][b][c]!=-1)return dp[a][b][c];
	if(a<b&&b<c) return dp[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	else return dp[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}
int main()
{
	memset(dp,-1,sizeof(dp));
	while(1)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a==-1&&b==-1&&c==-1)break;
		printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
	}
	return 0;
}
