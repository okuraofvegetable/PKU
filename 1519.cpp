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
string itos(int x)
{
	stringstream ss;
	ss << x;
	return ss.str();
}
int main()
{
	string x,t;
	while(1)
	{
		cin >> x;
		if(x=="0")break;
		int sum=INF;
		t=x;
		while(sum>=10)
		{
			sum=0;
			for(int i=0;i<t.size();i++)sum+=t[i]-'0';
			t=itos(sum);
		}
		cout << t << endl;
	}
	return 0;
}
