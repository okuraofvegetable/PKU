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
bool ex[105];
int main()
{
	while(1)
	{
		memset(ex,false,sizeof(ex));
		vector<int> vec;
		while(1)
		{
			int k;
			scanf("%d",&k);
			if(k==0)break;
			if(k==-1)goto end;
			ex[k]=true;
			vec.pb(k);
		}
		int ans=0;
		for(int i=0;i<vec.size();i++)if(vec[i]%2==0&&ex[vec[i]/2])ans++;
		cout << ans << endl;
	}
	end:;
	return 0;
}
