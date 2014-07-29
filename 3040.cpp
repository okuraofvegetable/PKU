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
int N,C,ans=0;
struct coin{int v,b;};
coin vec[20];
bool comp(coin a,coin b)
{
	return a.v>b.v;
}
int main()
{
	scanf("%d %d",&N,&C);
	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&vec[i].v,&vec[i].b);
		if(vec[i].v>=C)ans+=vec[i].b,vec[i].b=0;
	}
	sort(vec,vec+N,comp);
	for(;;)
	{
		int sum=0;
		int num=INF;
		int used[20];
		memset(used,0,sizeof(used));
		for(int i=0;i<N;i++)
		{
			if(sum>=C)break;
			int r=min((C-sum)/vec[i].v,vec[i].b);
			if(r==0)continue;
			used[i]=r;
			sum+=r*vec[i].v;
		}
		for(int i=N-1;i>=0;i--)
		{
			if(sum>=C)break;
			if(vec[i].b==0)continue;
			int r=min((C-sum-1)/vec[i].v+1,vec[i].b-used[i]);
			if(r==0)continue;
			used[i]+=r;
			sum+=r*vec[i].v;
			num=min(num,vec[i].b/used[i]);
		}
		if(sum<C)break;
		for(int i=0;i<N;i++)if(used[i]!=0)num=min(num,vec[i].b/used[i]);
		for(int i=0;i<N;i++)vec[i].b-=used[i]*num;
		ans+=num;
	}
	printf("%d\n",ans);
	return 0;
}
