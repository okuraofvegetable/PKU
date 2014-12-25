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
#define EQ(a,b) (abs((a)-(b))<eps)
#define sq(X) ((X)*(X))
int dp[2][105],a[2][105],b[2][105];
int h[100100],N,C;
int main()
{
	scanf("%d %d",&N,&C);
	for(int i=0;i<N;i++)scanf("%d",&h[i]);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=100;j++)
		{
			dp[i%2][j]=INF;
			a[i%2][j]=INF;
			b[i%2][j]=INF;
		}
		for(int j=h[i];j<=100;j++)
		{
			if(i==0)dp[i%2][j]=sq(j-h[i]);
			else dp[i%2][j]=min(a[(i-1)%2][j]-j*C,b[(i-1)%2][j]+j*C)+sq(j-h[i]);
		}
		for(int j=100;j>=0;j--)
		{
			if(j==100)a[i%2][j]=dp[i%2][j]+j*C;
			else a[i%2][j]=min(a[i%2][j+1],dp[i%2][j]+j*C);
		}
		for(int j=0;j<=100;j++)
		{
			if(j==0)b[i%2][j]=dp[i%2][j]-j*C;
			else b[i%2][j]=min(b[i%2][j-1],dp[i%2][j]-j*C);
		}
	}
	int ans = INF;
	for(int i=0;i<=100;i++)ans = min(ans,dp[(N-1)%2][i]);
	printf("%d\n",ans);
	return 0;
}
