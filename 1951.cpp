#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
int main()
{
	string s,ans;
	getline(cin,s);
	bool alph[26];
	vector<int> vec;
	memset(alph,0,sizeof(alph));
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='.'||s[i]==','||s[i]=='?')ans+=s[i];
		else if((s[i]==' ')&&ans.size()>0&&ans[ans.size()-1]!=' ')ans+=s[i];
		else if(s[i]>='A'&&s[i]<='Z')
		{
			if(s[i]=='A'||s[i]=='I'||s[i]=='U'||s[i]=='E'||s[i]=='O')continue;
			if(!alph[s[i]-'A'])
			{
				alph[s[i]-'A']=true;
				ans+=s[i];
			}
		}
		else ans+=s[i];
	}
	for(int i=1;i<ans.size();i++)
	{
		if((ans[i]=='.'||ans[i]==','||ans[i]=='?'||ans[i]==' ')&&ans[i-1]==' ')vec.pb(i-1);
	}
	vec.pb(INF);
	int p=0;
	for(int i=0;i<ans.size();i++)
	{
		if(i==ans.size()-1&&ans[i]==' ')continue;
		if(vec[p]==i)
		{
			p++;
		}
		else
		{
			cout << ans[i];
		}
	}
	cout  << endl;
	return 0;
}

