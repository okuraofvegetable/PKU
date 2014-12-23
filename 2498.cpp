#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[3]={9,3,7};
int main()
{
	int n;
	scanf("%d",&n);
	char s[20];
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		int len=strlen(s);
		int sum=0;
		int p,q;
		for(int j=len-1;j>=0;j--)
		{
			if(s[j]=='?')
			{
				p=a[(len-1-j)%3];
				q=j;
				continue;
			}
			sum+=a[(len-1-j)%3]*(s[j]-'0');
		}
		int ans=10-(sum%10);
		ans%=10;
		while(ans%p!=0)ans+=10;
		ans/=p;
		s[q]='0'+ans;
		printf("Scenario #%d:\n%s\n",i+1,s);
		puts("");
	}
	return 0;
}
