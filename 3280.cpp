#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 2000000000
char s[2050];
int n,m;
int cost[30];
int memo[2050][2050];
int rec(int a,int b)//[a,b)
{
	if(b-a==1)return 0;
	if(memo[a][b]!=INF)return memo[a][b];
	if(s[a]==s[b-1])return memo[a][b]=rec(a+1,b-1);
	if(cost[s[a]-'a']==INF)return memo[a][b]=rec(a,b-1)+cost[s[b-1]-'a'];
	if(cost[s[b-1]-'a']==INF)return memo[a][b]=rec(a+1,b)+cost[s[a]-'a'];
	return memo[a][b]=min(rec(a+1,b)+cost[s[a]-'a'],rec(a,b-1)+cost[s[b-1]-'a']);
}
int main()
{
	scanf("%d %d",&n,&m);
	scanf("%s",s);
	for(int i=0;i<30;i++)cost[i]=INF;
	for(int i=0;i<n;i++)
	{
		char p;
		int  a,b;
		cin >> p;
		scanf("%d %d",&a,&b);
		cost[p-'a']=min(a,b);
	}
	int len=strlen(s);
	for(int i=0;i<=len;i++)
	{
		for(int j=0;j<=len;j++)
		{
			memo[i][j]=INF;
		}
	}
	printf("%d\n",rec(0,len));
	return 0;
}
