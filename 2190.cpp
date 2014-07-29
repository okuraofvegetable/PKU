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
	string s;
	cin >> s;
	int c;
	int res=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='?')
		{
			c=10-i;
		}
		else if(s[i]=='X')
		{
			res+=10*(10-i);
		}
		else
		{
			res+=(s[i]-'0')*(10-i);
		}
	}
	for(int i=0;i<=10;i++)
	{
		if((res+i*c)%11==0)
		{
			if(c==1&&i==10)
			{
				cout << 'X' <<endl;
			}
			else if(i!=10)
			{
				cout << i << endl;
			}
			else goto next;
			return 0;
		}
	}
	next:
	cout << -1 << endl;
	return 0;
}
