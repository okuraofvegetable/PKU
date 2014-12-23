#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int,int> P;
#define fi first
#define sec second
int N;
int A[205][205],B[205][205];
bool used[205][205];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int abs(int a)
{
	return ((a<0)?-a:a);
}
int bfs(int x,int y)
{
	int res=0,min_dist=100000;
	queue<P> q;
	q.push(P(x,y));
	memset(used,false,sizeof(used));
	used[x][y]=true;
	while(!q.empty())
	{
		P a = q.front();
		q.pop();
		if(abs(x-a.fi)+abs(y-a.sec)>min_dist)continue;
		if(A[a.fi][a.sec]!=0)
		{
			if(res!=0)return 0;
			min_dist = abs(x-a.fi)+abs(y-a.sec);
			res = A[a.fi][a.sec];
			continue;
		}
		for(int i=0;i<4;i++)
		{
			int nx=a.fi+dx[i],ny=a.sec+dy[i];
			if(nx<0||nx>=N||ny<0||ny>=N)continue;
			if(used[nx][ny])continue;
			q.push(P(nx,ny));
			used[nx][ny]=true;
		}
	}
	return res;
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&A[i][j]);
			B[i][j]=A[i][j];
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(A[i][j]==0)
			{
				B[i][j]=bfs(i,j);
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%d%c",B[i][j],((j==N-1)?'\n':' '));
		}
	}
	return 0;
}
