#include <cstdio>
#include <cstring>
using namespace std;
#define MOD 1000000
int T,A,B,S,cnt=0;
int m[1010];
int a[1010];
int dp[2][100100];
int main()
{
	scanf("%d %d %d %d",&T,&A,&S,&B);
	for(int i=0;i<A;i++)
	{
		int x;
		scanf("%d",&x);
		if(m[x]==0)a[cnt++]=x;
		m[x]++;
	}
	//dp[i+1][j]:=iまででj個使った時の個数
	//dp[i+1][j]=Σ(k=0,min(m[i],j))dp[i][j-k] 
	//if(m[i]>=j)dp[i+1][j]=dp[i][j]+Σ(k=1,min(m[i],j))dp[i][j-k]
	//		       =dp[i][j]+Σ(k=0,min(m[i],j-1))dp[i][j-1-k]
	//		       =dp[i][j]+dp[i+1][j-1]
	//else       dp[i+1][j]=dp[i][j]+Σ(k=1,min(m[i],j))dp[i][j-k]
	//		       =dp[i][j]+Σ(k=0,min(m[i],j-1))dp[i][j-1-k]-dp[i][j-1-m[i]]
	//		       =dp[i][j]+dp[i+1][j-1]-dp[i][j-1-m[i]]
	memset(dp,0,sizeof(0));
	dp[0][0]=1;
	for(int i=0;i<cnt;i++)
	{
		for(int j=0;j<=A;j++)
		{
			if(j==0)dp[(i+1)%2][j]=dp[i%2][j];
			else if(m[a[i]]>=j)dp[(i+1)%2][j]=(dp[i%2][j]+dp[(i+1)%2][j-1])%MOD;
			else dp[(i+1)%2][j]=(dp[i%2][j]+dp[(i+1)%2][j-1]-dp[i%2][j-1-m[a[i]]]+MOD)%MOD;
			//printf("%d ",dp[(i+1)%2][j]);
		}
		//puts("");
	}
	int ans=0;
	for(int i=S;i<=B;i++)
	{
		ans+=dp[cnt%2][i];
		ans%=MOD;
	}
	printf("%d\n",ans);
	return 0;
}
