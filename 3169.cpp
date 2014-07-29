#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 2000000000
struct edge
{
	int from,to,cost;
	edge(int f,int t,int c):from(f),to(t),cost(c){}
};
vector<edge> edges;
int d[1050];
int N,ML,MD;
int main()
{
	scanf("%d %d %d",&N,&ML,&MD);
	for(int i=1;i<N;i++)
	{
		edge in(i,i-1,0);
		edges.push_back(in);
	}
	for(int i=0;i<ML;i++)
	{
		int AL,BL,DL;
		scanf("%d %d %d",&AL,&BL,&DL);
		AL--;BL--;//1...N -> 0...N-1
		edge in(AL,BL,DL);
		edges.push_back(in);
	}
	for(int i=0;i<MD;i++)
	{
		int AD,BD,DD;
		scanf("%d %d %d",&AD,&BD,&DD);
		AD--;BD--;
		edge in(BD,AD,-DD);
		edges.push_back(in);
	}
	fill(d,d+N,INF);
	d[0]=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<edges.size();j++)
		{
			edge e=edges[j];
			if(d[e.to]>d[e.from]+e.cost)
			{
				d[e.to]=d[e.from]+e.cost;
				if(i==N-1)
				{
					//negative loop exists
					printf("-1\n");
					return 0;
				}
			}
		}
	}
	if(d[N-1]==INF)
	{
		//can't arrive at N-1
		printf("-2\n");
		return 0;
	}
	printf("%d\n",d[N-1]);
	return 0;
}
