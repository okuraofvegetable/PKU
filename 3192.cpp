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
typedef unsigned long long ull;
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
string s[8];
int n;
ull B=1000000007ull;
int ans=INF;
string merge(string a,string b)
{
	int cov=0;
	ull ha=0ull,hb=0ull,t=1ull;
	int A=a.size(),B=b.size();
	for(int i=min(A,B);i>0;i--)
	{
		if(a.substr(a.size()-i)==b.substr(0,i))return a+b.substr(i);
	}
	return a+b;
}
void solve(vector<int> v)
{
	string S=s[v[0]];
	for(int i=1;i<n;i++)S=merge(S,s[v[i]]);
	int Sl=S.size();
	ans=min(ans,Sl);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)cin >> s[i];
	vector<int> v(n);
	for(int i=0;i<n;i++)v[i]=i;
	do{solve(v);}while(next_permutation(v.begin(),v.end()));
	printf("%d\n",ans);
	return 0;
}
