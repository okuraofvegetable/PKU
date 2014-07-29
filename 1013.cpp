#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
string s[3][3];
int w[13],we[3];
bool check(int x,int p)//p 0:light 1:heavy
{
	memset(w,0,sizeof(w));
	if(p)w[x]=1;else w[x]=-1;
	for(int i=0;i<3;i++)
	{
		we[0]=0,we[1]=0;
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<s[i][j].size();k++)
			{
				we[j]+=w[(s[i][j][k]-'A')];
			}
		}
		if(s[i][2]=="up"&&we[0]>we[1])continue;
		if(s[i][2]=="down"&&we[0]<we[1])continue;
		if(s[i][2]=="even"&&we[0]==we[1])continue;
		return false;
	}
	printf("%c is the counterfeit coin and it is %s.\n",'A'+x,((p==0)?"light":"heavy"));
	return true;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin >> s[j][0] >> s[j][1] >> s[j][2];
		}
		for(int j=0;j<12;j++)
		{
			for(int k=0;k<2;k++)
			{
				if(check(j,k))goto end;
			}
		}
		end:;
	}
	return 0;
}
