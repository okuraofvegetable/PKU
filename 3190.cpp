#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> T;
#define fi first
#define sec second
int N,ans=0;
priority_queue<P,vector<P>,greater<P> > q;
T time[50010];
int end[50010];
int stall[50010];
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d %d",&(time[i].fi.fi),&(time[i]).fi.sec);
	for(int i=0;i<N;i++)time[i].sec=i;
	sort(time,time+N);
	for(int i=0;i<N;i++)
	{
		if(q.empty())
		{
			end[ans]=time[i].fi.sec;
			q.push(P(end[ans],ans));
			stall[time[i].sec]=ans;
			ans++;
			continue;
		}
		if((q.top()).fi<time[i].fi.fi)
		{
			P a=q.top();
			q.pop();
			end[a.sec]=time[i].fi.sec;
			stall[time[i].sec]=a.sec;
			q.push(P(end[a.sec],a.sec));
		}
		else
		{
			end[ans]=time[i].fi.sec;
			q.push(P(end[ans],ans));
			stall[time[i].sec]=ans;
			ans++;
		}
	}
	printf("%d\n",ans);
	for(int i=0;i<N;i++)printf("%d\n",stall[i]+1);
	return 0;
}
