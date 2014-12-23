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
struct BIT
{
	int bit[10000];
	void clear()
	{
		memset(bit,0,sizeof(bit));
	}
	void add(int i,int x)
	{
		while(i<=5005)
		{
			bit[i]+=x;
			i += i&-i;
		}
	}
	int sum(int i)
	{
		int res=0;
		while(i)
		{
			res += bit[i];
			i -= i&-i;
		}
		return res;
	}
}bit;
int a[6000];
int N;
int get_color(int x,int K)
{
	int col = a[x];
	col += bit.sum(x);
	if(x-K>=1)col -= bit.sum(x-K);
	return col%2;
}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		char c;
		scanf(" %c",&c);
		if(c=='B')a[i]=1;
		else a[i]=0;
	}
	int v=N+1,num;
	for(int i=1;i<=N;i++)
	{
		bit.clear();
		int cnt = 0;
		for(int j=1;j<=N-i+1;j++)
		{
			int col = get_color(j,i);
			if(col)
			{
				bit.add(j,1);
				cnt++;
			}
		}
		bool flag = true;
		for(int j=N-i+2;j<=N;j++)
		{
			if(get_color(j,i)==1)
			{
				flag=false;
				break;
			}
		}
		if(flag&&v>cnt)
		{
			v = cnt;
			num = i;
		}
	}
	printf("%d %d\n",num,v);
	return 0;
}
