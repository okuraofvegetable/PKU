#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
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
int N,M;
P a[10010];
int ex[1010];
void Fill(int l,int r)
{
	if(r<l)
	{
		ex[l]++;ex[N]--;
		ex[0]++;ex[r]--;
	}
	else
	{
		ex[l]++;ex[r]--;
	}
	return;
}
int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)
	{
		scanf("%d %d",&a[i].fi,&a[i].sec);
		a[i].fi--;
		a[i].sec--;
	}
	int ans = N-1;
	for(int i=0;i<N;i++)
	{
		memset(ex,0,sizeof(ex));
		for(int j=0;j<M;j++)
		{
			if(a[j].fi>a[j].sec)swap(a[j].fi,a[j].sec);
			if(a[j].fi<=i&&i<a[j].sec)Fill(a[j].sec,a[j].fi);
			else Fill(a[j].fi,a[j].sec);
		}
		for(int j=1;j<=N;j++)ex[j]+=ex[j-1];
		int cnt = 0;
		for(int j=0;j<N;j++)if(ex[j]>0)cnt++;
		ans = min(ans,cnt);
	}
	cout << ans << endl;
	return 0;
}
