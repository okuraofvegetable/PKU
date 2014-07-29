#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define pb push_back
int a[100];
int main()
{
	string s1,s2;
	cin >> s1;
	cin >> s2;
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	for(int i=0;i<s1.size();i++)
	{
		for(int j=0;j<s2.size();j++)
		{
			a[i+j]+=((s1[i]-'0')*(s2[j]-'0'));
		}
	}
	for(int i=0;i<85;i++)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	int id=99;
	while(a[id]==0&&id>=0)id--;
	if(id==-1)
	{
		printf("0\n");
		return 0;
	}
	for(int i=id;i>=0;i--)printf("%d",a[i]);
	printf("\n");
	return 0;
}
