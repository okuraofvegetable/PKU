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
int mat[2010][2010];
int h[2010],L[2010],R[2010];
int n,m;
stack<int> *s;
int solve()
{
	s = new stack<int>();
	for(int i=0;i<n;i++)
	{
		while(!s->empty()&&h[s->top()]>=h[i])s->pop();
		if(s->empty())L[i]=0;
		else L[i]=s->top()+1;
		s->push(i);
	}
	delete s;
	s = new stack<int>();
	for(int i=n-1;i>=0;i--)
	{
		while(!s->empty()&&h[s->top()]>=h[i])s->pop();
		if(s->empty())R[i]=m;
		else R[i]=s->top();
		s->push(i);
	}
	delete s;
	int res = -1;
	for(int i=0;i<n;i++)res = max(res,h[i]*(R[i]-L[i]));
	return res;
}
int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		memset(mat,0.,sizeof(mat));
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&mat[i][j]);
		int ans = 0;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(mat[i][j])h[j]++;
				else h[j]=0;
			}
			ans = max(ans,solve());
		}
		printf("%d\n",ans);
	}
	return 0;
}
