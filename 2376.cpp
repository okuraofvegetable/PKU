#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> P;
#define fi first
#define sec second
int N,T,ans=0;
P time[25100];
int main()
{
	scanf("%d %d",&N,&T);
	for(int i=0;i<N;i++)scanf("%d %d",&time[i].fi,&time[i].sec);
	sort(time,time+N);
	priority_queue<int> q;
	int push_cnt=0;
	int end=0;
	while(end<T)
	{
		while(push_cnt<N&&time[push_cnt].fi<=end+1)
		{
			q.push(time[push_cnt].sec);
			push_cnt++;
		}
		if(q.empty())
		{
			printf("-1\n");
			return 0;
		}
		if(q.top()==end)
		{
			printf("-1\n");
			return 0;
		}
		end=q.top();
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}
