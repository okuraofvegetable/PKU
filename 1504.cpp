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
int num[2][110];
int ans[110];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		memset(num,0,sizeof(num));
		memset(ans,0,sizeof(ans));
		string s1,s2;
		cin >> s1 >> s2;
		for(int i=0;i<s1.size();i++)num[0][i]=s1[i]-'0';
		for(int i=0;i<s2.size();i++)num[1][i]=s2[i]-'0';
		int k=0;
		for(int i=0;i<110;i++)
		{
			int sum=k;
			sum+=num[0][i]+num[1][i];
			k=sum/10;
			ans[i]=sum%10;
		}
		int s,t;
		for(int i=0;i<110;i++)if(ans[i]!=0)
		{
			s=i;
			break;
		}
		for(int i=109;i>=0;i--)if(ans[i]!=0)
		{
			t=i;
			break;
		}
		for(int i=s;i<=t;i++)printf("%d",ans[s++]);
		printf("\n");
	}
	return 0;
}
