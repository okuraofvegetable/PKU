#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 2000000000
double d[1<<5][2];
double p[100100][5];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<(1<<5);i++)
	{
		d[i][0]=INF;
		d[i][1]=-INF;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<5;j++)
		{
			scanf("%lf",&p[i][j]);
		}
		for(int j=0;j<(1<<5);j++)
		{
			double res = 0;
			for(int k=0;k<5;k++)
			{
				if(j&(1<<k))res += p[i][k];
				else res -= p[i][k];
			}
			d[j][0]=min(d[j][0],res);
			d[j][1]=max(d[j][1],res);
		}
	}
	double ans = -INF;
	for(int i=0;i<(1<<5);i++)ans = max(ans,d[i][1]-d[i][0]);
	printf("%.2f\n",ans);
	return 0;
}
