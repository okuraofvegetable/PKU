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
map<string,string> ma;
int main()
{
	string s;
	while(1)
	{
		string key,value;
		getline(cin,s);
		if(s.size()<2)break;
		stringstream ss(s);
		ss >> value >> key;
		ma[key]=value;
	}
	while(1)
	{
		string key;
		if(!(cin >> key))break;
		if(ma.find(key)==ma.end())printf("eh\n");
		else cout << ma[key] << endl;
	}
	return 0;
}
