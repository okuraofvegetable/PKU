#include <cstdio>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int,int> P;
#define fi first
#define sec second
multiset<int> *s;
int T,n;
P stick[5050];
int main()
{
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		int ans=0;
		s = new multiset<int>();
		multiset<int>::iterator it;
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d %d",&stick[i].fi,&stick[i].sec);
		sort(stick,stick+n);
		for(int i=0;i<n;i++)
		{
			if(s->empty())
			{
				ans++;
				s->insert(stick[i].sec);
				continue;
			}
			it=s->upper_bound(stick[i].sec);
			if(it==s->begin())
			{
				ans++;
				s->insert(stick[i].sec);
			}
			else
			{
				it--;
				s->erase(it);
				s->insert(stick[i].sec);
			}
		}
		printf("%d\n",ans);
		delete s;
	}
	return 0;
}
