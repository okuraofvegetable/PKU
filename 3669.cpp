#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int,int> P;
#define fi first
#define sec second
#define INF 2000000000
int M;
int X[50010],Y[50010],T[50010];
int des[400][400];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int used[400][400];
queue<P> q;
int ans=INF;
int main()
{
	scanf("%d",&M);
	for(int i=0;i<400;i++)
	{
		for(int j=0;j<400;j++)
		{
			des[i][j]=INF;
			used[i][j]=INF;
		}
	}
	for(int i=0;i<M;i++)
	{
		scanf("%d %d %d",&X[i],&Y[i],&T[i]);
		des[X[i]][Y[i]]=min(des[X[i]][Y[i]],T[i]);
		for(int j=0;j<4;j++)
		{
			int nx=X[i]+dx[j],ny=Y[i]+dy[j];
			if(nx>=0&&ny>=0)
			{
				des[nx][ny]=min(des[nx][ny],T[i]);
			}
		}
	}
	q.push(P(0,0));
	used[0][0]=0;
	while(!q.empty())
	{
		P a=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=a.fi+dx[i],ny=a.sec+dy[i];
			if(nx>=0&&ny>=0&&used[nx][ny]==INF&&des[nx][ny]>used[a.fi][a.sec]+1)
			{
				used[nx][ny]=used[a.fi][a.sec]+1;
				q.push(P(nx,ny));
				//printf("%d %d\n",nx,ny);
				if(des[nx][ny]==INF)
				{
					ans=used[nx][ny];
					goto end;
				}
			}
		}
	}
	end:;
	if(ans!=INF)printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}
