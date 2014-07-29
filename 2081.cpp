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
bool used[10000000];
vector<int> seq;
int main()
{
	used[0]=0;
	seq.pb(0);
	for(int i=1;i<=500000;i++)
	{
		int last=seq.back();
		if(last-i>0&&!used[last-i])
		{
			used[last-i]=true;
			seq.pb(last-i);
		}
		else
		{
			used[last+i]=true;
			seq.pb(last+i);
		}
	}
	while(1)
	{
		int k;
		scanf("%d",&k);
		if(k==-1)break;
		printf("%d\n",seq[k]);
	}
	return 0;
}
