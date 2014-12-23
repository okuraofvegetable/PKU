#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int a[10];
int main()
{
	string s,p;
	while(1)
	{
		cin >> s;
		if(s==".")break;
		p=s;
		reverse(s.begin(),s.end());
		memset(a,0,sizeof(a));
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='.')continue;
			a[s[i]-'0']++;
			if(s[i]=='6')a[9]++;
			if(s[i]=='9')a[6]++;
			if(s[i]=='2')a[5]++;
			if(s[i]=='5')a[2]++;
			for(int j=s[i]-'0'+1;j<10;j++)if(a[j]>0)
			{
				int cnt  = 0;
				string t;
				a[j]--;
				if(j==6)a[9]--;
				if(j==9)a[6]--;
				if(j==5)a[2]--;
				if(j==2)a[5]--;
				for(int k=0;k<10;k++)
				{
					for(int l=0;l<a[k];l++)t += '0'+k;
					if(k==2)a[5]-=a[2];
					if(k==6)a[9]-=a[9];
				}
				sort(t.begin(),t.end());
				reverse(t.begin(),t.end());
				for(int k=0;k<i;k++)if(s[k]!='.')s[k]=t[cnt++];
				s[i]='0'+j;
				goto end;
			}
		}
		end:;
		reverse(s.begin(),s.end());
		if(p==s)cout << "The price cannot be raised." << endl;
		else cout << s << endl;
	}
	return 0;
}
