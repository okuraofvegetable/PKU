#include <cstdio>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> P;
#define fi first
#define sec second
priority_queue<P,vector<P>,greater<P> > q[2600];
int C,L,ans=0;
P range[2600];
P screen[2600];
bool used[2600];
int main()
{
	scanf("%d %d",&C,&L);
	for(int i=0;i<C;i++)scanf("%d %d",&range[i].fi,&range[i].sec);
	for(int i=0;i<L;i++)scanf("%d %d",&screen[i].fi,&screen[i].sec);
	sort(screen,screen+L);
	for(int i=0;i<L;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(range[j].fi<=screen[i].fi&&screen[i].fi<=range[j].sec)
			{
				q[i].push(P(range[j].sec,j));
			}
		}
	}
	for(int i=0;i<L;i++)
	{
		int cnt=0;
		while(!q[i].empty()&&cnt<screen[i].sec)
		{
			P a=q[i].top();
			q[i].pop();
			if(used[a.sec])continue;
			ans++;
			cnt++;
			used[a.sec]=true;
		}
	}
	printf("%d\n",ans);
	return 0;
}
