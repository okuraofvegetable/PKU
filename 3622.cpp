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
int N,M;
P grass[100100];
P cow[100100];
ll ans=0ll;
int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)scanf("%d %d",&cow[i].sec,&cow[i].fi);
	for(int i=0;i<M;i++)scanf("%d %d",&grass[i].sec,&grass[i].fi);
	sort(cow,cow+N);
	sort(grass,grass+M);
	int end=M-1;
	multiset<int> ms;
	/*cout << "Cows" << endl;
	for(int i=0;i<N;i++)cout << cow[i].fi << ' ' << cow[i].sec << endl;
	cout << "Grasses" << endl;
	for(int i=0;i<M;i++)cout << grass[i].fi << ' ' << grass[i].sec << endl;
	*/
	for(int i=N-1;i>=0;i--)
	{
		while(end>=0&&grass[end].fi>=cow[i].fi)ms.insert(grass[end--].sec);
		multiset<int>::iterator it = ms.lower_bound(cow[i].sec);
		if(it==ms.end())
		{
			printf("-1\n");
			return 0;
		}
		ans+=*it;
		ms.erase(it);
	}
	printf("%lld\n",ans);
	return 0;
}
