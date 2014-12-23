#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
char s[2500],t[2500];
int l,r;
int C()
{
	int sl=l,sr=r;
	while(sl<sr)
	{
		if(s[sl]>s[sr])return 1;
		else if(s[sl]<s[sr])return 0;
		sl++;sr--;
	}
	return 0;
}
int main()
{
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)cin >> s[i];
	l=0,r=n-1;
	for(int i=0;i<n;i++)
	{
		int g = C();
		if(g==0)t[cnt++]=s[l++];
		else t[cnt++]=s[r--];
	}
	for(int i=0;i<n;i++)
	{
		cout << t[i];
		if((i+1)%80==0)cout << endl;
	}
	if(n%80!=0)cout << endl;
	return 0;
}
