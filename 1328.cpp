#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<double,double> P;
#define fi first
#define sec second
int n;
long long d;
int case_cnt=0;
long long X[1050],Y[1050];
P range[1050];
int main()
{
	while(1)
	{
		case_cnt++;
		scanf("%d %lld",&n,&d);
		if(n==0&&d==0)break;
		bool flag=false;
		for(int i=0;i<n;i++)
		{
			scanf("%lld %lld",&X[i],&Y[i]);
			if(llabs(Y[i])>d)flag=true;
		}
		if(flag)
		{
			printf("Case %d: -1\n",case_cnt);
			continue;
		}
		for(int i=0;i<n;i++)
		{
			range[i].fi=(double)X[i]-sqrt(d*d-Y[i]*Y[i]);
			range[i].sec=(double)X[i]+sqrt(d*d-Y[i]*Y[i]);
		}
		sort(range,range+n);
		int ans=0;
		int cur=0,cnt=0;
		while(cur<n)
		{
			while(cnt<n&&range[cnt].fi<=range[cur].sec)
			{
				range[cur].sec=min(range[cur].sec,range[cnt].sec);
				cnt++;
			}
			ans++;
			cur=cnt;
		}
		printf("Case %d: %d\n",case_cnt,ans);
	}
	return 0;
}
