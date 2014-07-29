#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	string s;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cin >> s;
		int j,ret=0,res=0;
		for(j=0;j<s.size();j++)
		{
			if(s[j]==':')break;
			ret*=10;
			ret+=s[j]-'0';
		}
		j++;
		for(;j<s.size();j++)
		{
			res*=10;
			res+=s[j]-'0';
		}
		if(res!=0)
		{
			cout << 0 << endl;
		}
		else if(ret>12)
		{
			cout << ret-12 << endl;
		}
		else
		{
			cout << ret+12 << endl;
		}
	}
	return 0;
}
