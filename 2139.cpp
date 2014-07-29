#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 200000000
#define pb push_back
int dp[305][305];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)dp[i][j]=0;
			else dp[i][j]=INF;
		}
	}
	for(int i=0;i<m;i++)
	{
		int t;
		scanf("%d",&t);
		vector<int> vec;
		for(int j=0;j<t;j++)
		{
			int a;
			scanf("%d",&a);
			a--;
			vec.pb(a);
		}
		for(int j=0;j<t;j++)
		{
			for(int k=j+1;k<t;k++)
			{
				dp[vec[j]][vec[k]]=1;
				dp[vec[k]][vec[j]]=1;
			}
		}
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	double ans=INF;
	for(int i=0;i<n;i++)
	{
		double res=0.0;
		for(int j=0;j<n;j++)
		{
			res+=dp[i][j];
		}
		ans=min(ans,res);
	}
	int answer=(int)((ans/(n-1))*100);
	printf("%d\n",answer);
	return 0;
}
