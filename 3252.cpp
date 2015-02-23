#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define pb push_back
vector<int> v;
const int geta = 40;
int dp[40][100][2][2];
int rec(int x,int d,bool f,bool f2)
{
	if(x==v.size())
	{
		if(d>=0&&!f2)return 1;
		else return 0;
	}
	if(dp[x][d+geta][f][f2]!=-1)return dp[x][d+geta][f][f2];
	int res = 0;
	if(f)
	{
		for(int i=0;i<=v[x];i++)
		{
			int nd = d;
			bool nf,nf2;
			if(!f2&&i==0)nd++;
			else if(i!=0)nd--;
			if(i==v[x])nf=true;
			else nf = false;
			if(f2&&i==0)nf2=true;
			else nf2=false;
			res += rec(x+1,nd,nf,nf2);
		}
	}
	else
	{
		for(int i=0;i<=1;i++)
		{
			int nd = d;
			bool nf2;
			if(!f2&&i==0)nd++;
			else if(i!=0)nd--;
			if(f2&&i==0)nf2=true;
			else nf2=false;
			res += rec(x+1,nd,false,nf2);
		}

	}
	return dp[x][d+geta][f][f2]=res;
}
int solve(int x)
{
	v.clear();
	while(x)
	{
		v.pb(x%2);
		x/=2;
	}
	memset(dp,-1,sizeof(dp));
	reverse(v.begin(),v.end());
	return rec(0,0,true,true);
}
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d\n",solve(b)-solve(a-1));
	return 0;
}
