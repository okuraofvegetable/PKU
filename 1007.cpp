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
#define EQ(a,b) (abs((a)-(b))<eps)
string s[105];
int n,m;
vector<P> v;
int count(string str)
{
	int cnt=0;
	for(int i=0;i<str.size();i++)
	{
		for(int j=0;j<i;j++)
		{
			if(str[i]<str[j])cnt++;
		}
	}
	return cnt;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)cin >> s[i];
	for(int i=0;i<m;i++)v.pb(mp(count(s[i]),i));
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)cout << s[v[i].sec] << endl;
	return 0;
}
