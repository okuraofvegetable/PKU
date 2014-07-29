#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int a[30];
int mx;
int main()
{
	memset(a,0,sizeof(a));
	string s;
	for(int i=0;i<4;i++)
	{
		getline(cin,s);
		for(int j=0;j<s.size();j++)if(s[j]>='A'&&s[j]<='Z')a[s[j]-'A']++;
	}
	for(int j=0;j<30;j++)mx=max(mx,a[j]);
	for(int j=mx;j>=1;j--)
	{
		for(int k=0;k<26;k++)
		{
			if(a[k]>=j)cout << '*';
			else cout << ' ';
			if(k!=25)cout << ' ';
			else cout << endl;
		}
	}
	for(int j=0;j<26;j++)
	{
		cout << char('A'+j);
		if(j!=25)cout << ' ';
		else cout << endl;
	}
	return 0;
}
