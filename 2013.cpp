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
	for(int s=1;;s++)
	{
		int n;
		scanf("%d",&n);
		if(n==0)break;
		vector<string> v(n);
		for(int i=0;i<n;i++)cin >> v[i];
		printf("SET %d\n",s);
		for(int i=0;i<n/2;i++)cout << v[i*2] << endl;
		if(n&1)cout << v[n-1] << endl;
		for(int i=n-(n&1)-1;i>=n/2;i--)cout << v[(i-n/2)*2+1] << endl;
	}
	return 0;
}

