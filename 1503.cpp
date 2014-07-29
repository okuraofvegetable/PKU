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
string s[110];
int ans[110];
int num[110][110];
int main()
{
	int cnt=0;
	while(1)
	{
		cin >> s[cnt++];
		if(s[cnt-1]=="0")break;
	}
	for(int i=0;i<cnt;i++)reverse(s[i].begin(),s[i].end());
	for(int i=0;i<cnt;i++)
	{
		for(int j=0;j<s[i].size();j++)
		{
			num[i][j]=s[i][j]-'0';
		}
	}
	int k=0;
	for(int i=0;i<110;i++)
	{
		int sum=k;
		for(int j=0;j<cnt;j++)
		{
			sum+=num[j][i];
		}
		k=sum/10;
		ans[i]=sum%10;
	}
	int m;
	for(int i=109;i>=0;i--)if(ans[i]!=0)
	{
		m=i;
		break;
	}
	for(int i=m;i>=0;i--)printf("%d",ans[i]);
	printf("\n");
	return 0;
}
