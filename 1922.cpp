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
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)break;
		double min_time=INF;
		for(int i=0;i<n;i++)
		{
			int time,v;
			scanf("%d %d",&v,&time);
			if(time<0)continue;
			min_time=min(min_time,(double)time+4500.0/(v*5.0/18.0));
		}
		cout << ceil(min_time) << endl;
	}
	return 0;
}
