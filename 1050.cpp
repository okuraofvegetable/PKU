#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int f[105][105];
int sum(int a,int b,int c,int d)
{
	return f[c][d]-f[a-1][d]-f[c][b-1]+f[a-1][b-1];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&f[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=n;j++)
		{
			f[i][j]+=f[i][j-1];
		}
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=2;i<=n;i++)
		{
			f[i][j]+=f[i-1][j];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=i;k<=n;k++)
			{
				for(int l=j;l<=n;l++)
				{
					ans=max(ans,sum(i,j,k,l));
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
