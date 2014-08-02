#include <cstdio>
#include <set>
using namespace std;
int f[10][10];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
set<int> s;
void dfs(int x,int y,int d,int p)
{
	if(d==6)
	{
		s.insert(p);
		return;
	}
	int np=p*10;
	np+=f[x][y];
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>=0&&ny>=0&&nx<5&&ny<5)dfs(nx,ny,d+1,np);
	}
	return;
}
int main()
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			scanf("%d",&f[i][j]);
		}
	}
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			dfs(i,j,0,0);
		}
	}
	printf("%d\n",(int)s.size());
	return 0;
}
