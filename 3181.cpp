#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int N,K;
struct Int
{
	int digit[50];
	Int()
	{
		memset(digit,0,sizeof(digit));
	}
	void add(Int b)
	{
		int k=0;
		for(int i=0;i<50;i++)
		{
			int p=k+digit[i]+b.digit[i];
			if(p>=10)k=1;
			else k=0;
			digit[i]=p%10;
		}
		return;
	}
	void set(string s)
	{
		for(int i=0;i<s.size();i++)digit[i]=s[s.size()-1-i]-'0';
		return;
	}
	void print()
	{
		int p=49;
		while(digit[p]==0)p--;
		for(int i=p;i>=0;i--)printf("%d",digit[i]);
		puts("");
		return;
	}
};
Int dp[105][1010];
int main()
{
	//dp[i][j]:=i$までつかってj$払う組合せの数
	//dp[i][j]=Σ(k=0)dp[i-1][j-i*k]
	//dp[i][j]=dp[i-1][j]+Σ(k=1)dp[i-1][j-i*k]
	//	  =dp[i-1][j]+Σ(k=0)dp[i-1][j-i-i*k];
	//	  =dp[i-1][j]+dp[i][j-i]
	scanf("%d %d",&N,&K);
	dp[0][0].set("1");
	for(int i=1;i<=K;i++)
	{
		for(int j=0;j<=N;j++)
		{
			if(j>=i)
			{
				dp[i][j].add(dp[i-1][j]);
				dp[i][j].add(dp[i][j-i]);
			}
			else dp[i][j].add(dp[i-1][j]);
		}
	}
	dp[K][N].print();
	return 0;
}
