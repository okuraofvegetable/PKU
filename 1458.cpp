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
int dp[1000][1000];
int main()
{
	string s1,s2;
	while(cin >> s1 >> s2)
	{
		memset(dp,0,sizeof(dp));
		for(int i=0;i<s1.size();i++)
		{
			for(int j=0;j<s2.size();j++)
			{
				if(s1[i]==s2[j])dp[i+1][j+1]=dp[i][j]+1;
				else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
			}
		}
		printf("%d\n",dp[s1.size()][s2.size()]);
	}
	return 0;
}
